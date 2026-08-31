//Brute Force
//Time Complexity: O(nlogn)
//Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector < int > arr(n);
    // int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    // sort(arr, arr + n);
    cout << arr[n - 1] << endl;

}

//Optimal 
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
    int max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << max << endl;
}
