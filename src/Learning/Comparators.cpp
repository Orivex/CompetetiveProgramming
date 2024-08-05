#include <bits/stdc++.h>

using namespace std;


struct Group {
    int a, b, c; //c is the boss of b and b is boss of a
    bool operator<(const Group &y){
        if(a != y.a) {return a < y.a;}
        return b < y.b;
    }
};

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    vector<Group> groups;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        groups.push_back({a, b, c});
    }
    
    sort(begin(groups), end(groups));

    for(Group g : groups) {
        cout << g.a << " " << g.b << " " << g.c << endl;
    }

}