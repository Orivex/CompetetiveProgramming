#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    map<int, vector<int>> adjList;

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        adjList[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> roadNeed;
    set<int> visited;
    for(auto it : adjList) {
        int vertex = it.first;

        if(visited.find(vertex) != visited.end())
            continue;

        roadNeed.push_back(vertex);

        stack<int> s;
        s.push(vertex);

        while(!s.empty()) {
            int current = s.top();
            s.pop();

            visited.insert(current);

            for(int neighbor : adjList[current]) {
                if(visited.find(neighbor) != visited.end())
                    continue;
                s.push(neighbor);
            }
        }
    }


    cout << roadNeed.size()-1 << endl;
    for (int i = 0; i < roadNeed.size()-1; i++)
    {
        cout << roadNeed[i] << " " << roadNeed[i+1] << endl;
    }
    
}