#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    deque<int> numbers(n);
    deque<int> leftnumbers;
    iota(numbers.begin(), numbers.end(), 1);

    while (numbers.size() > 1)
    {

        for (int i = 0; i < numbers.size(); i++)
            if (i & 1)
                cout << numbers[i] << " ";
            else
                leftnumbers.push_back(numbers[i]);

        // logic for bringing the last to front

        if (numbers.size() & 1)
        {
            int first = leftnumbers[leftnumbers.size() - 1];
            leftnumbers.pop_back();
            leftnumbers.push_front(first);
            numbers.clear();
            numbers = leftnumbers;
        }
        else
            numbers = leftnumbers;
        leftnumbers.clear();
    }
    cout << numbers[0];
}