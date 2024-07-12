#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j);
bool isValid(int x, int y);

int n, m;
vector<vector<bool>> visited;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;

    visited.resize(n);
    for (int i = 0; i < n; i++)
    {
        visited[i].resize(m);
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;

            if(ch == '#') {
                visited[i][j] = true;
            }
        }
        
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j] == false){
                count++,
                dfs(i, j);
            }
        }
        
    }

    cout << count;

}


void dfs(int i, int j) {
    visited[i][j] = true;

    for(auto move : moves) {
        int nextX = i + move.first;
        int nextY = j + move.second;
        if (isValid(nextX, nextY) == true) {
            dfs(nextX, nextY);
        }
    }
}

bool isValid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(visited[x][y] == true)
        return false;
    return true;
}