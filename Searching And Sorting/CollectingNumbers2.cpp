#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    // arr[i] holds the value at index i
    // pos[v] holds the index of value v
    vector<int> arr(n + 1);
    vector<int> pos(n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    
    // 1. Precompute initial rounds
    int rounds = 1;
    for(int i = 1; i < n; i++){
        // If the next number appears before the current number, we need a new round
        if(pos[i+1] < pos[i]) {
            rounds++;
        }
    }    
    
    // 2. Process swaps
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        // Get the actual values being swapped
        int x = arr[a];
        int y = arr[b];
        
        // Use a set to automatically deduplicate affected value pairs (left, right)
        set<pair<int,int>> affected;
        if(x - 1 >= 1) affected.insert({x - 1, x});
        if(x + 1 <= n) affected.insert({x, x + 1});
        if(y - 1 >= 1) affected.insert({y - 1, y});
        if(y + 1 <= n) affected.insert({y, y + 1});
        
        // 3. Subtract old state
        for(auto p : affected){
            if(pos[p.first] > pos[p.second]) {
                rounds--;
            }
        }
        
        // 4. Execute the swap in both arrays
        swap(arr[a], arr[b]);
        pos[x] = b;
        pos[y] = a;
        
        // 5. Add new state
        for(auto p : affected){
            if(pos[p.first] > pos[p.second]) {
                rounds++;
            }
        }
        
        // 6. Print result
        cout << rounds << "\n";
    }   

    return 0;
}