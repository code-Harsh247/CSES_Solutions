#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n,x;
    cin>>n>>x;
    vll weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    sort(weights.begin(),weights.end());
    int count = 0;
    int ptrLow = 0,ptrHigh = n-1;
    vll alloted(n,0);
    while(ptrLow<=ptrHigh){
        int w1 = weights[ptrLow];
        int w2 = weights[ptrHigh];
        if(w1+w2<=x){
            alloted[ptrLow] = 1;
            alloted[ptrHigh] = 1;
            count++;
            ptrLow++;
            ptrHigh--;
        }
        else {
            ptrHigh--;
        }
    }
    for(auto it: alloted){
        if(it == 0)count++;
    }
    cout<<count<<endl;

    return 0;
}