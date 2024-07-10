#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    unordered_map<int, vector<int>> tree;
    tree[1] = vector<int>();

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[i] = tree[boss];
        tree[i].insert(tree[i].begin(), boss);
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;

        if ((k - 1) >= static_cast<int>(tree[x].size())) {
            cout << -1 << "\n";
        } else {
            cout << tree[x][k - 1] << "\n";
        }
    }

    return 0;
}
