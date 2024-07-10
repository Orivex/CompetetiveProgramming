#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n, m;
vector<vector<int>> adjList;
vector<int> parent;
vector<int> visited;

void bfs()
{
	visited[1] = 1;
	queue<int> q;
	q.push(1);

	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		for(auto neighbor: adjList[current])
		{
			if(visited[neighbor] == 0)
			{
				visited[neighbor] = true;
				parent[neighbor] = current;
				q.push(neighbor);
			}
		}
	} 
}

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;

    adjList.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1);

    for (int i = 0; i <= n; ++i)
    {
        parent[i] = -1;
    }
    

    for(int i; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a); 
    }

    bfs();  

    if(parent[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int current = n;

    stack<int> s;

    while(current != -1) {
        s.push(current);
        current = parent[current];
    }

    cout << s.size() << " \n";

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

}