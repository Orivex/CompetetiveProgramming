#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        arr[i].first = value;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());
    int rounds = 1;

    for (int i = 0; i < n-1; i++)
    {
        if(arr[i].second > arr[i+1].second) 
            rounds++;
    }
    
    cout << rounds << endl;
}