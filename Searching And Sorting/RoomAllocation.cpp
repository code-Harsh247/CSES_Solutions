#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

typedef struct {
    int arriveTime, deptTime, custInd;
} customer;

bool compare(const customer& a, const customer& b) {
    return a.arriveTime < b.arriveTime;
}

class hotel {
public:
    set<pair<int, int>> rooms; // {deptTime, roomNum}
    vector<int> roomAllocation;
    int maxRoomCount = 0;

    hotel(int n) {
        roomAllocation.resize(n);
    }

    void addRoom(int deptTime, int custInd) {
        int roomCount = rooms.size();
        int newRoomNum = roomCount + 1;
        maxRoomCount = max(maxRoomCount, newRoomNum);
        rooms.insert({deptTime, newRoomNum});
        roomAllocation[custInd] = newRoomNum;
    }

    void accomadate(int arriveTime, int deptTime, int custInd) {
        if (rooms.empty()) {
            addRoom(deptTime, custInd);
            return;
        }
        int earliestDepart = (*rooms.begin()).first;
        if (earliestDepart < arriveTime) {
            int roomId = (*rooms.begin()).second;
            rooms.erase(rooms.begin());
            rooms.insert({deptTime, roomId});
            roomAllocation[custInd] = roomId;
        } else {
            addRoom(deptTime, custInd);
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<customer> customers(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }
    sort(customers.begin(), customers.end(), compare);

    hotel h(n);
    for (int i = 0; i < n; i++) {
        int arrive = customers[i].arriveTime;
        int depart = customers[i].deptTime;
        int custInd = customers[i].custInd;
        h.accomadate(arrive, depart, custInd);
    }

    cout << h.maxRoomCount << endl;
    for (int i = 0; i < n; i++) {
        cout << h.roomAllocation[i] << " ";
    }
    cout << endl;

    return 0;
}
