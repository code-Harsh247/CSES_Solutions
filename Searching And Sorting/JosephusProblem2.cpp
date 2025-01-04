#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int n, k;
    cin >> n >> k;
    ordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }
    int i=0;
    while(s.size()){
        i += k;
        i %= s.size();

        auto it = s.find_by_order(i);
        cout<<*it<<" ";
        s.erase(it); 
    }
    cout<<endl;
    return 0;
}