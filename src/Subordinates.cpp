#include <bits/stdc++.h>

using namespace std;



int getSubordinates(int current);

int n;
vector<vector<int>> tree;
vector<int> solution;


int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;

    tree.resize(n);
    solution.resize(n);

    for (int i = 1; i < n; i++)
    {
        int boss;
        cin >> boss;
        tree[boss-1].push_back(i);
    }

    getSubordinates(0);

    for(int s : solution) {
        cout << s << " ";
    }
}


int getSubordinates(int current) {
    if(tree[current].empty()) {
        solution[current] = 0;
        return 1;
    }

    int mySubordinates = 0;
    for (int i = 0; i < tree[current].size(); i++)
    {
        mySubordinates += getSubordinates(tree[current][i]);
    }

    solution[current] = mySubordinates;

    return mySubordinates+1;
    
}