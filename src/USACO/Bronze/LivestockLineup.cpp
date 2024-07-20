#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<int, int>> constraints, vector<int> permutation);

string cow[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("lineup.in","r",stdin); 
	freopen("lineup.out","w",stdout); 

    int n;
    cin >> n;
    vector<pair<int, int>> constraints(n);

    for (int i = 0; i < n; i++)
    {
        string cow1, cow2, t;

        cin >> cow1;
        cin >> t >> t >> t >> t;
        cin >> cow2;

        int i1 = find(cow, cow+8, cow1) - cow;
        int i2 = find(cow, cow+8, cow2) - cow;

        constraints.push_back({i1, i2});
    }
    

    solve(constraints, vector<int>({0, 1, 2, 3, 4, 5, 6, 7}));
    
    
}

void solve(vector<pair<int, int>> constraints, vector<int> permutation) {
    
    for (int i = 0; i < constraints.size(); i++)
    {
        int i1 = find(permutation.begin(), permutation.end(), constraints[i].first) - permutation.begin();
        int i2 = find(permutation.begin(), permutation.end(), constraints[i].second) - permutation.begin();

        if(abs(i1-i2) > 1) {
            next_permutation(permutation.begin(), permutation.end());
            solve(constraints, permutation);
            return;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        cout << cow[permutation[i]] << endl;
    }

    return;
    
}