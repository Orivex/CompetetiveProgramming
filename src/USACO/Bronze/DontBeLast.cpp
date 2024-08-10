#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("notlast.in","r",stdin); 
	freopen("notlast.out","w",stdout); 

    int n;
    cin >> n;
    map<string, int> m = {{"Bessie", 0}, {"Elsie", 0},{"Daisy", 0},{"Gertie", 0},{"Henrietta", 0},{"Annabelle", 0},{"Maggie", 0}};
    
    for (int i = 0; i < n; i++)
    {
        string name;
        int milk;
        cin >> name >> milk;
        m[name] += milk;
    }

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    for(auto t : m) {
        if(t.second < smallest) {
            second_smallest = smallest;
            smallest = t.second;
        }
        else if(t.second < second_smallest && t.second != smallest) {
            second_smallest = t.second;
        }
    }

    bool found = false;
    string name = "";
    for(auto t : m) {
        if(t.second == second_smallest) {
            if(found == true) {
                cout << "Tie" << endl;
                return 0;
            }

            found = true;
            name = t.first;
        }
    }

    if(found == false) {
        cout << "Tie" << endl;
        return 0;
    }

    cout << name << endl;
    
}