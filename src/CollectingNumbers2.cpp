#include <bits/stdc++.h>

using namespace std;

bool comparer(const pair<int, int> &a, const pair<int, int> &b);

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;

    cin >> n >> m;

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
    for (int i = 0; i < arr.size()-1; i++)
    {
        if(arr[i].second > arr[i+1].second) 
            rounds++;
    }

    sort(arr.begin(), arr.end(), comparer);

    //Wrong
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(b < a)
            swap(a, b);

        if(arr[a-1].first > arr[b-1].first) {
            rounds--;
        }
        else {
            rounds++;
        }

        swap(arr[a-1], arr[b-1]);

        cout << rounds << endl;
    }
    
}

bool comparer(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}