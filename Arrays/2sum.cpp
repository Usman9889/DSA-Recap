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
// Better solution using Hashing
//Time Complexity = O(n)
//Space Complexity = O(n)
vector<int> BetterSolution(vector<int>& arr, int target) {
      int n = arr.size();

      map<int,int>mpp;
      for(int i=0; i<n; i++){
            int a = arr[i];
            int moreNeeded = target - a;
            if(mpp.find(moreNeeded) != mpp.end()){
                  return {mpp[moreNeeded], i};
            }
            mpp[a] = i;
      } 
}
// Optimal solution using 2-pointer technique(if array is not sorted)
//Time Complexity = O(nlogn)
//Space Complexity = O(1)
vector<int> OptimalSolution(vector<int>& arr, int target) {
      int n = arr.size();

      vector<pair<int,int>> arrIndex;
      // The pairs are sorted based on the value (.first), while the original index (.second) stays attached to that value.
      for(int i=0; i<n; i++){
            arrIndex.push_back({arr[i], i});
      }
      sort(arrIndex.begin(), arrIndex.end());
      
      int left = 0, right = n-1;
      while(left < right){
            int sum = arrIndex[left].first + arrIndex[right].first;
            if(sum == target){
                  // If the sum is equal to the target, return the original indices
                  return {arrIndex[left].second, arrIndex[right].second};
            }
            else if(sum < target){
                  left++;
            }
            else{
                  right--;
            }
      }
}
// Optimal solution using 2-pointer technique(if array is sorted)
//Time Complexity = O(n)
//Space Complexity = O(1)
vector<int> OptimalSolutionSorted(vector<int>& arr, int target) {
      int n = arr.size();

      int left = 0, right = n-1;
      while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == target){
                  // If the sum is equal to the target, return the original indices
                  return {left, right};
            }
            else if(sum < target){
                  left++;
            }
            else{
                  right--;
            }
      }
}
int main(){
      vector<int> arr = {2, 6, 5, 8, 11};
      int target = 14;

      vector<int> result = BruteForce(arr, target);
      cout << result[0] << " " << result[1] << endl;

      vector<int> better = BetterSolution(arr, target);
      cout << better[0] << " " << better[1] << endl;

      vector<int> optimal = OptimalSolution(arr, target);
      cout << optimal[0] << " " << optimal[1] << endl;

      vector<int> optimalSorted = OptimalSolutionSorted(arr, target);
      cout << optimalSorted[0] << " " << optimalSorted[1] << endl;
}