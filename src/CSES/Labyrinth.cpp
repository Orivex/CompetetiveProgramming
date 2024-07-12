#include <bits/stdc++.h>
#include <string>

using namespace std;
    
int n, m;
vector<vector<char>> labyMap;
pair<int, int> A;
pair<int, int> B;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);


    cin >> n >> m;

    labyMap.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { 
            cin >> labyMap[i][j];
            
            if(labyMap[i][j] == 'A') {
                A = make_pair(i, j);
            }
            else if(labyMap[i][j] == 'B') {
                B = make_pair(i, j);
            }
        }
        
    }

    labyMap[B.first][B.second] = '.';
    
    //BFS

    bool found = false;
    queue<pair<int, int>> q;
    q.push(A);


    while(!q.empty() && found == false) {
        auto current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        if(x == B.first && y == B.second) {
            found = true;
        }
        
        if(x > 0 && labyMap[x-1][y] == '.') {
            labyMap[x-1][y] = 'U';
            q.push(make_pair(x-1, y));
        }
        
        if(y > 0 && labyMap[x][y-1] == '.') {
            labyMap[x][y-1] = 'L';
            q.push(make_pair(x, y-1));
        }
        
        if(x < n-1 && labyMap[x+1][y] == '.') {
            labyMap[x+1][y] = 'D';
            q.push(make_pair(x+1, y));
        }

        if(y < m-1 && labyMap[x][y+1] == '.') {
            labyMap[x][y+1] = 'R';
            q.push(make_pair(x, y+1));
        }
    }

    if(found == false) {
        cout << "NO";
        return 0;
    }

    int x = B.first;
    int y = B.second;
    string path;

    while( !(x == A.first && y == A.second) ) {
        path += (labyMap[x][y]);

        switch (labyMap[x][y])
        {

        case 'U':
                x++;
            break;

        case 'L':
                y++;
            break;

        case 'D':
                x--;
            break;

        case 'R':
                y--;
            break;

        }
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl << path.length() << endl << path;

    return 0;

}