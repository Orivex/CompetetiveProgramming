#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int>> customers(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        customers[i] = make_pair(a, b);
        
    }

    sort(customers.begin(), customers.end());

    int maximum = 0;
    int current = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1e9);
    
    for (int i = 0; i < n; i++)
    {
        while(customers[i].first > pq.top() && !pq.empty()) {
            pq.pop();
            current--;
        }
        current++;
        pq.push(customers[i].second);
        maximum = max(maximum, current);
    }
    
    cout << maximum << endl;

}