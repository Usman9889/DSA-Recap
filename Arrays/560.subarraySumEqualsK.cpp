#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int bruteForce(vector<int> &nums, int k, int n) {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += nums[j];

            if(sum == k) {
                cnt++;
            }
        }
    }
    return cnt;
}
// Optimal using Hashing            
// Time Complexity: O(n)
// Space Complexity: O(n)
int Optimal(vector<int> &nums, int k, int n){
      map<int, int>mpp;
      mpp[0] = 1;
      int prefixSum = 0;
      int count = 0; 

      for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            int remove = prefixSum - k;
            if(mpp.find(remove) != mpp.end()){
                  count += mpp[remove];
            }
            mpp[prefixSum]++;
      }
      return count;
      }
int main() {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    int k = 3;
    int n = nums.size();

    int ans = bruteForce(nums, k, n);
    cout << ans << endl;

    int ans2 = Optimal(nums, k, n);
    cout << ans2 << endl;
}