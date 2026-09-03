#include<bits/stdc++.h>
using namespace std;
//Liner search approach
//Time complexity: O(n^2)
//Space complexity: O(1)
int missingNumberBruteForce(vector<int>& arr) {
      int n = arr.size() + 1;
      for(int i=1; i<=n; i++){
            bool found = false;
            for(int j=0; j<n-1; j++){
                  if(arr[j] == i){
                        found = true;
                        break;
                  }
            }
            if(!found) return i;
      }
      return -1; // This line should never be reached if input is valid
}
// Better approach(Hashing)
//Time complexity: O(n)
//Space complexity: O(n)
int missingNumberBetter(vector<int>& arr) {
      int n = arr.size() + 1;
      //Create hash array of size n+1 to get last index that is 5th
      vector<int>hash(n+1, 0);

      //store the frequencies of elements
      for(int i=0; i<n-1; i++){
            hash[arr[i]]++;
      }
      //find the missing number
      for(int i=1; i<=n; i++){
            if(hash[i] == 0){
                  return i;
            }
      }
      return -1;
}
// Optimal approach(Sum)
//Time complexity: O(n)
//Space complexity: O(1)
int missingNumberSum(vector<int>& arr) {
      int n = arr.size() + 1;
      int sum =0;
      for(int i=0; i<n-1; i++){
            sum +=arr[i];
      }
      // Calculate sum of 1 to n
      long long expSum = (n*(n+1))/2;

      // return the missing number
      return expSum - sum;
}
// Optimal approach(XOR)
//Time complexity: O(n)
//Space complexity: O(1)
int missingNumberXOR(vector<int>& arr) {
      int n = arr.size();
      int xor1 = 0, xor2 = 0;

      // XOR of all elements in the array
      for(int i=0; i<n; i++){
            xor2 ^= (i+1); // XOR all numbers from 1 to n
            xor1 ^= arr[i];  // XOR all array elements
      }
      xor2 ^= (n + 1);      // Include the last number

      // // XOR of all numbers from 1 to n if n = arr.size() + 1;
      // for(int i=1; i<=n; i++){
      //       xor2 ^= i;
      // }

      // The missing number is the XOR of the two results
      return xor1 ^ xor2;
}
int main(){
      vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
      cout << missingNumberBruteForce(arr) << endl;
      cout << missingNumberBetter(arr) << endl;
      cout << missingNumberSum(arr) << endl;
      cout << missingNumberXOR(arr) << endl;
}