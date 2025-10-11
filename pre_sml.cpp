#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> prev_sml(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++){
        while(!st.empty() && st.top()>arr[i]){
            st.pop();
        }
        if(!st.empty())
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 4, 3, 4, 5};
    vector<int> ans = prev_sml(arr);
    cout << "The the prevoius smallest element is {";
    for(auto &i: ans){
        cout << i << " ";
    }
    cout << "}" << " " << endl;
}