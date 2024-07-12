#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> applicants(n);
    for (int i = 0; i < n; i++)
    {
        cin >> applicants[i];
    }

    vector<int> apartments(m);
    for (int i = 0; i < m; i++)
    {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int count = 0;
    int ptr1 = 0;
    int ptr2 = 0;

    while(ptr1 < n) {

        while(ptr2 < m && apartments[ptr2] < applicants[ptr1]-k)
            ptr2++;

        if(abs(apartments[ptr2]-applicants[ptr1]) <= k) {
            ptr1++;
            ptr2++;
            count++;
        }
        else {
            ptr1++;
        }

    }

    cout << count;
    


    
    

}