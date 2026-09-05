#include<bits/stdc++.h>
using namespace std;
//Bruteforce
//Time Complexity = O(n^2)
//Space Complexity = O(1)
int BruteForce(vector < int > & arr, int k) {
    int maxLength = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// Optimal(2-Pointer)
int Optimal(vector<int>& arr, int k){
      int n = arr.size();
      int maxlength = 0;
      int left =0, right=0;
      int sum = 0;
      while(right < n){
            while(left <= right && sum >k){
                  sum -= arr[left];
                  left++;
            }
            if(sum == k){
                  maxlength = max(maxlength, right - left + 1);
            }
            right++;
            if(right < n){
                  sum += arr[right];
            }
      }
      return maxlength;
}
int main(){
      vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
      int k = 6;
      cout << BruteForce(arr, k) << endl;
      cout << Optimal(arr, k) << endl;
}