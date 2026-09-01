#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector < int > arr1(n);
    vector < int > arr2(m);
    vector < int > ans;
    // Input first n elements of arr1
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Input m elements of arr2
    for (int j = 0; j < m; j++) {
        cin >> arr2[j];
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {

            i++;
        }
        else if (arr1[i] > arr2[j]) {

            j++;
        }
        else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    // Print intersection
    for (int x: ans) {
        cout << x << " ";
    }
    return 0;
}