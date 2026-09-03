#include <bits/stdc++.h>
using namespace std;

// Using set
// Time Complexity: O((m+n)log(m+n))
// Space Complexity: O(n + m)
vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {

    set<int> st;

    st.insert(arr1.begin(), arr1.end());
    st.insert(arr2.begin(), arr2.end());

    vector<int> ans;

    for (auto it : st) {
        ans.push_back(it);
    }

    return ans;
}
// 2 pointer
// Time Complexity: O(n + m)
// Space Complexity: O(n + m) for returning the answer not in algorithm
vector<int> findUnionTwoPointers(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;

    vector<int> Union;
    while(i<n && j<m){
      if(arr1[i] < arr2[j]){
            if(Union.empty() || Union.back() != arr1[i]){
                  Union.push_back(arr1[i]);
            }
            i++;
      }
      else{
            if(Union.empty() || Union.back() != arr2[j]){
                  Union.push_back(arr2[j]);
            }
            j++;
      }
    }
    while(i<n){
      if(Union.empty() || Union.back() != arr1[i]){
            Union.push_back(arr1[i]);
      }
      i++;
    }
    while(j<m){
      if(Union.empty() || Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
      }
      j++;
    }
    return Union;
}
    
 
int main() {

    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

//     vector<int> result = findUnion(arr1, arr2);
    vector<int> result = findUnionTwoPointers(arr1, arr2);

    for (auto it : result) {
        cout << it << " ";
    }

    return 0;
}