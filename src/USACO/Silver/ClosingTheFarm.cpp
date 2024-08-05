#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> activated;
vector<bool> ansV;
vector<int> depth;

int findRoot(int a) {
    if(parent[a] == a) {
        return a;
    }

    parent[a] = findRoot(parent[a]);
    return parent[a];
}

void join(int a, int b) {
    parent[findRoot(a)] = findRoot(b);
}

int main(){ 

    freopen("closing.in","r",stdin); 
	freopen("closing.out","w",stdout);


    cin >> n >> m;

    adj.resize(n+1);
    parent.resize(n+1);
    activated.resize(n+1);
    depth.resize(n+1);
    ansV.resize(n+1);

    for (int i = 0; i < n+1; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> queries(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        queries[n-i-1] = a;
    }
    
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        int current = queries[i]; 
        components++;

        activated[current] = true;
        for (int j = 0; j < adj[current].size(); j++)
        {
            if(activated[adj[current][j]] && findRoot(current) != findRoot(adj[current][j])) {
                join(current, adj[current][j]);
                components--;
            }
        }
        ansV[n-i-1] = components == 1;
        
    }

    for (int i = 0; i < n; i++)
    {
        if(ansV[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    

}