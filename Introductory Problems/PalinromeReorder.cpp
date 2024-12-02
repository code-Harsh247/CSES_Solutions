#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    string half = "", oddChar = "";
    bool isPossible = true;

    for (auto &[ch, count] : freq) {
        if (count % 2 != 0) {
            if (!oddChar.empty()) {
                isPossible = false; // More than one odd character found.
                break;
            }
            oddChar = string(1, ch); // Store the odd character.
        }
        half += string(count / 2, ch); // Add half of the characters to `half`.
    }

    if (isPossible) {
        string palindrome = half + oddChar + string(half.rbegin(), half.rend());
        cout << palindrome << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
}
