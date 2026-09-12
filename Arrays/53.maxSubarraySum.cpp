#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int  bruteForce(vector<int> &arr){
      int n = arr.size();
      int maxSum = INT_MIN;
      for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                  sum += arr[j];
                  maxSum = max(maxSum, sum);
            }
      }
      return maxSum;
}

// Optimal Approach Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
int optimal(vector<int> &arr){
      int n = arr.size();
      int maxSum = INT_MIN;
      // current sum of subarray 
      int sum = 0;
      
      // starting index of current subarray
      int start = 0; 
        
      // indices of the maximum sum subarray
      int ansStart = 0, ansEnd = 0;

      for(int i = 0; i < n; i++){
            if(sum == 0){
                  start = i;
            }
            sum += arr[i];
            if(sum > maxSum){
                  maxSum = sum;
                  ansStart = start;
                  ansEnd = i;
            }
            if(sum < 0){
                  sum = 0;
            }
      }
       // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
      return maxSum;
}
int main(){
      vector<int> arr = {2, 3, 5, -2, 7, -4};
      int result = bruteForce(arr);
      cout << result << endl;

      int ans = optimal(arr);
      cout << ans << endl;
}