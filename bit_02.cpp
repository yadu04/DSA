#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<vector<int>> subset(vector<int> arr){
    int n=arr.size();
    int m=(1<<n);
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++){
        vector<int> temp;
        for (int j =0; j <n;j++){
            if(i&(1<<j)) {
               temp.push_back(arr[j]);
            } 
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 3};
    cout<<" The combination af the all possible subset is "<<endl;
    vector<vector<int>>ans=subset(arr);
    for(auto &i : ans){
        cout << "{";
        for(auto &j :i){
            cout << j<<" ";
        }
        cout << "},";
    }
    return 0;
}