#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main()
{
    ll n;
    cin >> n;
    if (n == 2 || n == 3)
        cout << "NO SOLUTION " << endl;
    else
    {
        for (ll i = 2; i <= n; i = i + 2)
        {
            cout << i << " ";
        }
        for (ll i = 1; i <= n; i = i + 2)
        {
            cout << i << " ";
        }
    }
    return 0;
}