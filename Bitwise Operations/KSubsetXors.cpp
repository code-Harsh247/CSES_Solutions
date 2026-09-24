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
    vector<int> b,r;
    int rank,count;
    public:
        Basis(){
            b.resize(32,0);
            r.resize(32,0);
            rank = 0;
            count = 0;
        }
        void insert(int x){
            count++;
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
        int getCount(){
            return count;
        }
        void reduce() {
            for(int i=31;i>=0;i--) r[i] = b[i];
            for(int i=0;i<32;i++){
                if(r[i]){
                    for(int j=i+1;j<32;j++){
                        if((r[j]>>i)&1) r[j]^=r[i];
                    }
                }
            }
        }
        int kthSmallest(int k){
            int ans=0;
            int idx = 0;
            for(int i=0;i<32;i++){
                if(r[i]){
                    if((k>>idx)&1) ans ^= r[i];
                    idx++;
                }
            }
            return ans;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    Basis b;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        b.insert(num);
    }
    b.reduce();
    int e = b.getCount() - b.getRank();
    for(int i=0;i<k;i++){
        int pos = (e>=20) ? 0: (i>>e);
        cout<<b.kthSmallest(pos)<<" ";
    }
    return 0;
}