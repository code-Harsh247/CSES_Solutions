#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){

    string s;
    cin>>s;
    int n = s.length();
    int l = 1,t=1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            t++;
        }
        else t = 1;
        if(t>l) l = t;
    }
    cout<<l<<endl;
    return 0;
}