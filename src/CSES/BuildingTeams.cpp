#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    map<int, vector<int>> adjList;

    for (int i = 1; i <= n; i++)
    {
        adjList[i] = vector<int>();
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    set<int> visited;
    vector<int> teamArray(n+1, -1); //Color array

    queue<int> q; //current node, next team

    for (int i = 1; i <= n; i++)
    {
        if(visited.find(i) != visited.end()) {
            continue;
        }

        teamArray[i] = 1;
        q.push(i);

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            visited.insert(current);

            int currentTeam = teamArray[current];
            int nextTeam;

            if(currentTeam == 1)
                nextTeam = 2;
            else 
                nextTeam = 1;

            for (int neighbor : adjList[current])
            {
                if(teamArray[neighbor] == -1) {
                    teamArray[neighbor] = nextTeam; 
                    q.push(neighbor);
                }
                else if(teamArray[neighbor] == currentTeam) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }

        }

    }

    
    for (int i = 1; i <= n; i++)
    {
        cout << teamArray[i] << " ";
    }
    
    return 0;

}