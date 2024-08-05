#include <bits/stdc++.h>
using namespace std;

bool impossible = false;
bool visited[100001];
vector<vector<pair<int, char>>> adj;
bool colors[100001];

void dfs(int current, int color) {
    if(visited[current])
        return;

    visited[current] = true;
    colors[current] = color;
    
    for (auto v : adj[current]) {
        if(visited[v.first]) {
            if(v.second == 'S' && colors[v.first] != color) { impossible = true ;};
            if(v.second == 'D' && colors[v.first] == color) { impossible = true ;};
        }
        else { 
            if(v.second == 'S')
                dfs(v.first, color);
            else
                dfs(v.first, !color);
        }
    }
    
}

int main(){ 

    freopen("revegetate.in","r",stdin); 
	freopen("revegetate.out","w",stdout);

    int n, m;
    cin >> n >> m;
    adj.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        char t;
        int a, b;
        cin >> t >> a >> b;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    string ans = "1";
    for (int i = 1; i <= n; i++)
    {
        if(visited[i])
            continue;

        ans += "0";
        dfs(i, 0);

        if(impossible)
            break;
    }   

    if(impossible)
        cout << 0 << endl;
    else 
        cout << ans << endl;

}
