#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;

    cin >> x >> n;

    set<long> lights;
    multiset<long> distance;

    lights.insert(0);
    lights.insert(x);
    distance.insert(x);

    int lightPos;

    for (int i = 0; i < n; i++)
    {
        cin >> lightPos;

        auto right = lights.upper_bound(lightPos);
        //auto left = lights.lower_bound(lightPos);
        //Better solution:
        auto left = right;
        left--;

        distance.erase(distance.find(*right - *left));
        distance.insert(*right - lightPos);
        distance.insert(lightPos - *left);
        lights.insert(lightPos);

        cout << *distance.rbegin() << " ";
    }
    
    

}