#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    
    multiset<int> tickets;

    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        auto lower = tickets.lower_bound(t);

        if(*lower == t) {
            cout << *lower << endl;
            tickets.erase(lower);
            continue;
        }

        if(lower == tickets.begin()) {
            cout << -1 << endl;
            continue;
        }

        lower--;

        cout << *lower << endl;
        tickets.erase(lower);
        
    }
    

}
