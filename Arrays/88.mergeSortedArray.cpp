#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    // nums1 must have space for n + m elements
    vector<int> arr1(n + m);
    vector<int> arr2(m);

    // Input first n elements of arr1
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Input m elements of arr2
    for (int j = 0; j < m; j++) {
        cin >> arr2[j];
    }

    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;

    // Merge from the end
    while (i >= 0 && j >= 0) {

        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } 
        else {
            arr1[k] = arr2[j];
            j--;
        }

        k--;
    }

    // Copy remaining elements of arr2
    while (j >= 0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }

    // Print merged array
    for (int i = 0; i < n + m; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}