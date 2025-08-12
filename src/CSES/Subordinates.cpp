#include <bits/stdc++.h>

using namespace std;



int getSubordinates(int current);

int n;
vector<vector<int>> parent;
vector<int> solution;


int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;

    parent.resize(n);
    solution.resize(n);

    for (int i = 1; i < n; i++)
    {
        int boss;
        cin >> boss;
        parent[boss-1].push_back(i);
    }

    getSubordinates(0);

    for(int s : solution) {
        cout << s << " ";
    }
}


int getSubordinates(int current) {
    if(parent[current].empty()) {
        solution[current] = 0;
        return 1;
    }

    int mySubordinates = 0;
    for (int i = 0; i < parent[current].size(); i++)
    {
        mySubordinates += getSubordinates(parent[current][i]);
    }

    solution[current] = mySubordinates;

    return mySubordinates+1;
    
}