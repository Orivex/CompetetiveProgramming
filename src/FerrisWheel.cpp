#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;

    cin >> n >> x;

    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i]; 
    }

    sort(weight.begin(), weight.end());

    int left = 0;
    int right = weight.size()-1;
    int count = 0;

    while(left < right) {

        while(weight[left] + weight[right] > x) {
            right--;
        }

        if(left >= right)
            break;

        count++;
        right--;
        left++;

    }

    count += weight.size()-2*count;

    cout << count;
    
    return 0;
}