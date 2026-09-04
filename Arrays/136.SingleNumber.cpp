#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity: O(n^2)
//Space complexity: O(1)
int bruteForce(vector<int>& arr){
      int n = arr.size();
      for(int i=0; i<n; i++){
            int cnt =0;
            for(int j=0; j<n; j++){
                  if(arr[i] == arr[j]){
                        cnt++;
                  }
            }
            if(cnt == 1){
                  return arr[i];
            }
      }
      return -1;
}

//Better approach(Hashing)
//Time complexity: O(n)
//Space complexity: O(n)
int betterApproach(vector<int>& arr){
      int n = arr.size();

      //Maximum value in the array 
      int maxi = arr[0];
      for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
      }

      //Declare and initialize hash of size maxi + 1
      vector<int>hash(maxi+1, 0);

      //Count the frequency of each number
      for(int i=0; i<n; i++){
            hash[arr[i]]++;
      }

      //Find the element that occurs exactly once
      for(int i=0; i<n; i++){
            if(hash[arr[i]] == 1){
                  return arr[i];
            }
      }

}
//Optimal Approach(XOR)
//Time complexity: O(n)
//Space complexity: O(1)
int optimalApproach(vector<int>& arr){
      int n = arr.size();
      int xorr = 0;
      for(int i=0; i<n; i++){
            xorr ^= arr[i];
      }
      return xorr;
}

int main(){
      vector<int> arr = {1, 2, 1, 4, 3, 2, 4};
      cout << bruteForce(arr) << endl;    
      cout << betterApproach(arr) << endl;
      cout << optimalApproach(arr) << endl;

}