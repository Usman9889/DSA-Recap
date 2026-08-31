#include<bits/stdc++.h>
using namespace std;

int main(){
      
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
      if(arr[i] > arr[(i+n) % n]){
            cnt++;
      }
    }
    if(cnt == 0 || cnt == 1){
        cout << "YES" << endl;
      }
      else{
            cout << "NO" << endl;
      }
}