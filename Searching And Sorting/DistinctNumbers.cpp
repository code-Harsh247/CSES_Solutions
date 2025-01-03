#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n;
    cin>>n;
    vll numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    int distinct = 1;
    for(int i=1;i<n;i++){
        if(numbers[i]!=numbers[i-1]){
            distinct++;
        }
    }
    cout<<distinct<<endl;
    return 0;
}