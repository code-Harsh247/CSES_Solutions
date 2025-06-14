    #include <bits/stdc++.h>
    using namespace std;

    #define INF 1000000000
    #define MOD 1000000007

    class DisjointSet{
        vector<int> size, parent;
        public:
        DisjointSet(int n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int getParent(int u){
            if(parent[u] == u) return u;
            return parent[u] = getParent(parent[u]);
        }
        void unionBySize(int u, int v){
            int pu = getParent(u);
            int pv = getParent(v);
            if(pu == pv) return;
            else if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

    typedef long long ll;
    typedef vector<ll> vll;
    bool isValid(int x,int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }

    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n, vector<char>(m,'#'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        vector<pair<int,int>> directions = {{0,1},{-1,0}};
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '.'){
                    for(auto dir : directions){
                        int row = i + dir.first;
                        int col = j + dir.second;
                        if(isValid(row, col, n, m) && grid[row][col] == '.'){
                            int nodeNum = i*m + j;
                            int adjNodeNum = row*m+col;
                            ds.unionBySize(nodeNum, adjNodeNum);
                        }
                    }
                }
            }
        }
        int rooms = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nodeNum = i*m + j;
                if(grid[i][j] == '.'){
                    int p = ds.getParent(nodeNum);
                    if(p == nodeNum) rooms++;
                }
            }
        }
        cout<<rooms<<endl;

        return 0;
    }