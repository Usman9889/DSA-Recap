// Brute Force
// Time Complexity: O(n)
// Space Complexity: O(d)
#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, d;
      cin >> n >> d;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      d = d % n;
      int temp[d];
      for(int i=0; i<d; i++){
            temp[i] = arr[i];
      }
      //shifting left by d
      for(int i=d; i<n; i++){
            arr[i-d] = arr[i];
      }
      //placing the elements of temp at the end
      for(int i=0; i<d; i++){
            arr[n-d+i] = temp[i];
      }
      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }
      return 0;
}
//Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, d;
      cin >> n >> d;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      d = d % n;
      // Reverse the entire array
      reverse(arr, arr + n);
      // Reverse the first d elements
      reverse(arr, arr + d);
      // Reverse the remaining elements
      reverse(arr + d, arr + n);
      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }
      return 0;
}
