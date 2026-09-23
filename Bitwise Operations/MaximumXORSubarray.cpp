#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

struct Node{
    Node* links[2] = {};
    bool isEnd = 0;
    Node* get(int b){
        return links[b];
    }
    void put(int b, Node* node){
        links[b] = node;
    }
    bool contains(int b){
        return links[b] != nullptr;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int b = (num>>i)&1;
            if(!node->contains(b)){
                node->put(b,new Node());
            }
            node = node->get(b);
        }
        node->isEnd = true;
    }
    int findMaxXor(int x){
        Node* node = root;
        int res = 0;
        for(int i=31;i>=0;i--){
            int b = (x>>i)&1;
            if(node->contains(1-b)){
                res = res | (1<<i);
                node = node->get(1-b);
            }
            else node = node->get(b);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        prefix[i] = prefix[i-1]^num;
    }
    Trie t;
    for(int i=1;i<=n;i++){
        t.insert(prefix[i]);
    }
    int maxXor = 0;
    for(int i=0;i<=n;i++){
        int x = prefix[i];
        maxXor = max(maxXor,t.findMaxXor(x));
    }
    cout<<maxXor<<endl;
    return 0;
}