//Brute force
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    // vector < int > arr(n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != arr[n - 1]) {
            cout << arr[i];
        }
        break;
    }
}