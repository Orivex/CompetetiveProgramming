#include <bits/stdc++.h>

using namespace std;

int getLongestRouteLength(int current);

vector<set<int>> tree;
set<int> solution;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    tree.resize(n);
    
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a-1].insert(b-1);
        tree[b-1].insert(a-1);
    }

    getLongestRouteLength(0);

    int max = 0;
    for(int length : solution)  {
        if(length > max) {
            max = length;
        }
    }

    cout << max << endl;


}

int getLongestRouteLength(int current) {
    if(tree[current].empty()) {
        return 1;
    }

    int maxLength1 = 0;
    int maxLength2 = 0;
    for (int node : tree[current])
    {
        tree[node].erase(current);
        int routeLength = getLongestRouteLength(node);

        if(routeLength > maxLength1) {
            int temp = maxLength1;
            maxLength1 = routeLength;
            maxLength2 = temp;
        }
        else if(routeLength > maxLength2) {
            maxLength2 = routeLength;
        }
    }

    solution.insert(maxLength1+maxLength2);

    return maxLength1+1;
    
}