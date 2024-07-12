#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int maxLength = 0;
    set<int> seq;
    int i = 0, j = 0;

    while(j < n) {
        int size = seq.size();
        maxLength = max(maxLength, size);

        if(seq.find(v[j]) != seq.end()) {
            while(v[i] != v[j]) {
                seq.erase(v[i]);
                i++;
            }
            i++;
        }

        seq.insert(v[j]);
        j++;
    }

    int size = seq.size();
    maxLength = max(maxLength, size);

    cout << maxLength << endl;
}