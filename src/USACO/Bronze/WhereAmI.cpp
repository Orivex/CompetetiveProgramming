#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("whereami.in","r",stdin); 
	freopen("whereami.out","w",stdout); 

    int n;
    cin >> n;
    string road;
    cin >> road;
    
    for (int i = 1; i <= n; i++)
    {
        set<string> sequence;
        bool unique = true;

        for (int j = 0; j < n-i+1; j++)
        {
            string newSeq;

            for (int k = j; k < i+j; k++)
            {
                newSeq += road[k];
            }
            
            if(sequence.find(newSeq) != sequence.end()) {
                unique = false;
                break;
            }

            sequence.insert(newSeq);

        }

        if(unique == true) {
            cout << i << endl;
            return 0;
        }
        
    }

    cout << n << endl;

}