#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
vector<int> next_greater_el(vector<int> &arr){
     int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    
    for (int i = n - 1; i >= 0;i--){
        while(!st.empty()&& st.top()<=arr[i])
            st.pop();
        if 
            (st.empty()) ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {2, 3, 1, 4, 1, 5};
    vector<int> ans = next_greater_el(arr);
    cout << "the next greater next of the arr is " << endl;
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}