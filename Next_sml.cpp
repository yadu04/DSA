#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // will store elements in increasing order

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    // remaining indices in stack have -1 (already set)
    return ans;
}
 int main(){
    vector<int > arr={4,8,5,2,25};
    vector<int> ans = nextSmallerElement(arr);
    for(auto i: ans){
        cout << i << " ";
    }

    cout << "The smallest elements of the array"  << endl;
 }