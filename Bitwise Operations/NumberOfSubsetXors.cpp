#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

class Basis{
    vector<int> b;
    int rank;
    public:
        Basis(){
            b.resize(32,0);
            rank = 0;
        }
        void insert(int x){
            for(int i=31;i>=0;i--){
                if(!((x>>i)&1)) continue;
                if(!b[i]){
                    b[i] = x;
                    rank++;
                    return;
                }
                x ^= b[i];
            }
        }
        int getRank(){
            return rank;
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Basis b;
    for(int i=0;i<n;i++){ 
        int num;
        cin>>num;
        b.insert(num);
    }
    int xors = 1<<(b.getRank());
    cout<<xors<<endl;

    return 0;
}