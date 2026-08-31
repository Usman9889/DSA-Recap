//Brute force
//Time Complexity: O(nlogn)
//Space Complexity: O(1)
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
//Better Approach (Two Pass search)
//Time Complexity: O(n)
//Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int Largest = -1, secondLargest = -1;
    //Finding largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > Largest) {
            Largest = arr[i];
        }
    }
    //Finding second largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] != Largest) {
            secondLargest = arr[i];
        }
    }
    cout << secondLargest;
}

//Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int Largest = -1, secondLargest = -1;
    //Finding largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > Largest) {
            secondLargest = Largest;
            Largest = arr[i];
        }
        else if(arr[i] < Largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    cout << secondLargest;
}