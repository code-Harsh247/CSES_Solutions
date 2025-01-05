#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i].first;
        numbers[i].second = i + 1;
    }
    sort(numbers.begin(), numbers.end());
    int front, rear, sum;
    for (int lockInd = 0; lockInd < n; lockInd++)
    {
        front = lockInd + 1;
        sum = 0;
        rear = n - 1;
        while (front < rear)
        {
            sum = numbers[lockInd].first + numbers[front].first + numbers[rear].first;
            if (sum == x)
            {
                cout << numbers[lockInd].second << " " << numbers[front].second << " " << numbers[rear].second;
                return 0;
            }
            else if (sum < x)
                front++;
            else
                rear--;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}