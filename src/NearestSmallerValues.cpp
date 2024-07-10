#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        bool found = false;

        while(!found && !s.empty()) {
            if(s.top().first < arr[i]) {
                cout << s.top().second+1 << " ";
                found = true;
            }
            else
                s.pop();
        }

        if(s.empty())
            cout << 0 << " ";

        s.push(make_pair(arr[i], i));
    }
    
    
}
