// Approaches:(For Brute Force use any sorting algorithm)
// 2. Better
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> sortBrute(vector<int> &nums) {
    int n = nums.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) cnt0++;
        else if(nums[i] == 1) cnt1++;
        else cnt2++;
    }

    int index = 0;
    while(cnt0--) nums[index++] = 0;
    while(cnt1--) nums[index++] = 1;
    while(cnt2--) nums[index++] = 2;

    return nums;
}
// Optimal: Dutch National Flag
// Time Complexity: O(n)
// Space Complexity: O(1)
vector <int> sortDutchNationalFlag(vector<int> &nums) {\
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;
}
int main() {
    vector<int> nums = {0, 2, 1, 2, 0, 1};

    nums = sortBrute(nums);
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    nums = sortDutchNationalFlag(nums);
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}