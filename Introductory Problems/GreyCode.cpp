#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void convertToBinary(int i,int n){
    string b = "";
    while(i!=0){
        char c = i%2==0? '0' : '1';
        b = c+b;
        i=i/2;
    }
    int s = b.size();
    string padding(n-s, '0');
    cout<<padding+b<<endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        convertToBinary(i^(i>>1), n);
    }
    return 0;
}