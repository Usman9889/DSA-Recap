#include<bits/stdc++.h>
using namespace std;

// BruteForce solution for the 2-sum problem
//Time Complexity = O(n^2)
//Space Complexity = O(1)

vector<int> BruteForce(vector<int>& arr, int target) {
      int n = arr.size();

      for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                  if(arr[i] + arr[j] == target ){
                        return {i,j};
                  }
            }
      }
}
int main(){
      vector<int> arr = {2, 6, 5, 8, 11};
      int target = 14;

      vector<int> result = BruteForce(arr, target);
      cout << result[0] << " " << result[1] << endl;
}