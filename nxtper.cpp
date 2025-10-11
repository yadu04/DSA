#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> nextper(vector<int> &arr, vector<vector<int>> &ans,int index){
    //base condition 
    if(index==arr.size()){
        ans.push_back(arr);
        return ans;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        nextper(arr,ans,index+1);
        swap(arr[index],arr[i]);

    }
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans;
    ans= nextper(arr,ans,0);
    
    cout<<" The combination of all possible permutation is  "<<endl;
    for (const auto &i: ans){
        for(auto &j:i){
            cout<<j<< " ";
        }
        cout<<endl;
    }
    return 0;

}