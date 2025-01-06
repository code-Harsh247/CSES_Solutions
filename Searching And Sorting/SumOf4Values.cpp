#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i].first;
        numbers[i].second = i+1;
    }
    sort(numbers.begin(), numbers.end());
    for(int lock1=0;lock1<n;lock1++){
        for(int lock2=lock1+1;lock2<n;lock2++){
            int front = lock2 + 1;
            int rear = n-1;
            int sum = 0;
            while(front < rear){
                sum = numbers[lock1].first + numbers[lock2].first + numbers[front].first + numbers[rear].first;

                if(sum == x){
                    cout<<numbers[lock1].second<<" "<<numbers[lock2].second<<" "<<numbers[front].second<<" "<<numbers[rear].second;
                    return 0;
                }
                else if(sum > x){
                    rear--;
                }
                else front++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}