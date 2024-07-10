#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int log = 0;
    while ((1 << log) <= n)
        log++;

    vector<vector<int>> up(n + 1, vector<int>(log, 0));
    vector<int> depth(n + 1, 0);
    vector<int> parent(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    for (int i = 1; i <= n; i++) {
        up[i][0] = parent[i];

        if (i != 1) {
            depth[i] = depth[parent[i]] + 1;
        }

        for (int j = 1; j < log; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;

        int current = x;

        if (depth[current] < k) {
            cout << -1 << "\n";
            continue;
        }

        for (int j = 0; j < log; j++) {
            if ((k & (1 << j)) != 0) { // Check if bit j is on
                current = up[current][j];
            }
        }

        cout << current << "\n";
    }

    return 0;
}
