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
    public:
        Basis(){
            b.resize(32,0);
        }
        void insert(int x){
            for(int i=31;i>=0;i--){
                if(!((x>>i)&1)) continue;
                if(!b[i]){
                    b[i] = x;
                    return;
                }
                x ^= b[i];
            }
        }
        int maxSubsetXor(){
            int ans = 0;
            for(int i=31;i>=0;i--){
                if(b[i] && !((ans>>i)&1)) ans ^= b[i];
            }
            return ans;
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    Basis B;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        B.insert(nums[i]);
    }
    cout<<B.maxSubsetXor()<<"\n";
    return 0;
}