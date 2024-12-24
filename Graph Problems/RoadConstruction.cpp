#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

class DisjointSet
{
public:
    vector<int> parents, rank,size;
    int compCount;
    int maxCompSize = -INF;
    int maxSize;
    DisjointSet(int n)
    {
        compCount = n;
        size.resize(n+1,1);
        maxSize = 1;
        parents.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parents[i] = i;
        }
        rank.resize(n + 1, 0);
    }
    int getParent(int u)
    {
        if (parents[u] == u)
            return u;
        else
            return parents[u] = getParent(parents[u]);
    }
    void unionByRank(int u, int v)
    {
        int pu = getParent(u);
        int pv = getParent(v);
        if (pu != pv)
        {
            if (rank[pu] > rank[pv])
            {
                parents[pv] = pu;
                size[pu]+=size[pv];
                maxSize = max(size[pu],maxSize);
            }
            else if (rank[pu] < rank[pv])
            {
                parents[pu] = pv;
                size[pv]+=size[pu];
                maxSize = max(size[pv],maxSize);
            }
            else
            {
                parents[pv] = pu;
                size[pu]+=size[pv];
                maxSize = max(size[pu],maxSize);
                rank[pu]++;
            }
            compCount--; // Merging reduces the component count.
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    DisjointSet sol(n);
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;
        sol.unionByRank(u, v);
        cout<<sol.compCount<<" "<<sol.maxSize<<endl;
        
    }
    return 0;
}