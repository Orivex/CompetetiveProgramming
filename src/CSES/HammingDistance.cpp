#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    unsigned int arr[n];

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        unsigned int num = stoi(s, nullptr, 2);
        arr[i] = num;
    }

    unsigned int minCount = 2147483647;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {

            unsigned int newCount = __popcount(arr[i] ^ arr[j]);

            minCount = min(minCount, newCount);
        }
    }

    cout << minCount;
}