#include<bits/stdc++.h>
using namespace std;
//Brute Force Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
void BruteForce(vector<int> & arr){
      int n = arr.size();
      vector<int>temp;
      // Store non-zero elements in temp
      for(int i=0; i<n; i++){
            if(arr[i] != 0){
                  temp.push_back(arr[i]);
            }
      }
      // Fill the remaining positions with zeros
      for(int i=temp.size(); i<n; i++){
            temp.push_back(0);
      }
      // Copy the modified array back to the original
      for(int i=0; i<n; i++){
            arr[i] = temp[i];
      }
      // Print the modified array
      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }   
}
//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
void Optimal(vector<int> & arr){
      int n = arr.size();
      int j = -1;
      // Find the first zero element
      for(int i=0; i<n; i++){
            if(arr[i] == 0){
                  j = i;
                  break;
            }
      }
      // If no zero element is found, return
      if(j == -1){
            return;
      }
      // Move all non-zero elements to the left
      for(int i=j+1; i<n; i++){
            if(arr[i] != 0){
                  swap(arr[i], arr[j]);
                  j++;
            }
      }
      // Print the modified array
      for(int i=0; i<n; i++){ 
            cout << arr[i] << " ";
      }
}
int main() {
      vector<int> arr = {0, 1, 0, 3, 12};
      BruteForce(arr);
      Optimal(arr);
}