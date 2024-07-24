#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> prefix(n+1);
    vector<int> flowers(n+1);
    cin >> flowers[1];
    prefix[1] = flowers[1];

    for (int i = 2; i < n+1; i++)
    {
        cin >> flowers[i];
        prefix[i] = prefix[i-1] + flowers[i];
    }

    int count = 0;
    for (int i = 1; i < n; i++)
    {
        set<float> photo;
        photo.insert(flowers[i]);
        for (int j = i+1; j < n+1; j++)
        {
            photo.insert(flowers[j]);
            float avg = (float)(prefix[j]-prefix[i-1]) / (float)(j-i+1);

            if(photo.find(avg) != photo.end()) {
                count++;
            }
        }
    }

    cout << (n+count) << endl;
    

}