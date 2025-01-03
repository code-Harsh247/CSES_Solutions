#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int count = 0;
    int ptr1,ptr2 = ptr1 = 0;
    while(ptr1<n && ptr2<m){
        int x = a[ptr1];
        int size = b[ptr2];
        if(size >= x-k && size <= x+k ){
            count++;
            ptr2++;
            ptr1++;
        }
        else if(size<x-k){
            ptr2++;
        }
        else if(size > x+k){
            ptr1++;
        }
    }
    cout<<count<<endl;

}
