#include<bits/stdc++.h>
using namespace std;

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
int main() {
      vector<int> arr = {0, 1, 0, 3, 12};
      BruteForce(arr);
}