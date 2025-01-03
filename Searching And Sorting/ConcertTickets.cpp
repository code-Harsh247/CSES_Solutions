#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int findTicket(int maxPrice, multiset<int> &availableTickets) {
    // Find the largest ticket <= maxPrice
    auto it = availableTickets.upper_bound(maxPrice);
    if (it == availableTickets.begin()) return -1; // No ticket <= maxPrice
    --it; // Move to the largest valid ticket
    int ticket = *it;
    availableTickets.erase(it); // Mark as purchased
    return ticket;
}

int main() {
    int n, m;
    cin >> n >> m;
    vll tickets(n), maxPrice(m);

    for (int i = 0; i < n; i++) cin >> tickets[i];
    for (int i = 0; i < m; i++) cin >> maxPrice[i];

    // Use a multiset to handle duplicates and maintain sorted order
    multiset<int> availableTickets(tickets.begin(), tickets.end());

    for (int i = 0; i < m; i++) {
        cout << findTicket(maxPrice[i], availableTickets) << endl;
    }

    return 0;
}
