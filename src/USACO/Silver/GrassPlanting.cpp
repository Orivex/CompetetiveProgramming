#include <bits/stdc++.h>
using namespace std;

//Explanation: https://usaco.guide/problems/usaco-894-grass-planting/solution
int main(){ 

    ifstream cin("planting.in");
    ofstream cout("planting.out");

    int n,  ans = 0;
    cin >> n;

    vector<int> tree[n+1];

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i = 1; i < n+1; i++){
        int temp = tree[i].size();
        ans = max(ans,temp);
    }

    cout << ans+1 << endl;
}