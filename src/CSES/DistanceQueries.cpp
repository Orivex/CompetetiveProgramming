#include <bits/stdc++.h>

using namespace std;

int get_lca(int a, int b, int n);
void pre_process(int n);
void dfs(int node, int parent, int currentDepth);
int LOG = 0;
vector<vector<int>> adjList;
vector<vector<int>> up;
vector<int> depth;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    adjList.resize(n);
    depth.resize(n);

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);    
        adjList[b].push_back(a);
    }
    
    pre_process(n);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int lca = get_lca(a, b, n);
        cout << depth[a]-depth[lca] + depth[b]-depth[lca] << endl;
        //Or depth[a]+depth[b] - 2*(depth[get_lca(a, b)])

    }
}

int get_lca(int a, int b, int n) {
    if(depth[a] < depth[b])
        swap(a, b);

    int k = depth[a] - depth[b];

    for (int j = 0; j < LOG; j++)
    {
        if(k & (1 << j))
            a = up[a][j];
    }

    if(a == b) //already found lca
        return a;

    for (int j = LOG-1; j >= 0; j--)
    {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

void pre_process(int n) {

    while((1 << LOG) <= n)
        LOG++;
    
    up.resize(n, vector<int>(LOG));
    up[0][0] = -1;

    dfs(0, -1, 0);

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else {
                up[i][j] = -1;
            }
        }
    }
}

void dfs(int node, int parent, int currentDepth) {
    depth[node] = currentDepth;
    up[node][0] = parent;

    for(auto child : adjList[node]) {
        if(child != parent) {
            dfs(child, node, currentDepth+1);
        }
    }

}