#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int ksubarry(int arr[],int n,int k){
    // int right=0,left=0;
    // int sum=arr[0];
    // int len=0;
    // while(right<n){
    //     if(sum==k){
    //         len=max(len,right-left+1);
    //     }
    //     if(left<=right && sum>k){
    //         sum-=arr[left];
    //         left++;
    //     } else {
    //         right++;
    //         if(right<n) {
    //             sum+=arr[right];
    //         }
    //     }
    // }
    // return len;

// using the hashmap approach
  int sum=0;
  int len=0;
  unordered_map<int,int> mp;
   for(int i=0;i<n;++i){
    sum+=arr[i];
    if(sum==k) {
        len=max(len,i+1); // if sum equals k, update length
    }
    long long rem=sum-k;
    if(mp.find(rem)!=mp.end()){
        int len=i-mp[rem];
        len=max(len,len);
    }  
    if(mp.find(sum)==mp.end()){
        mp[sum]=i; // store the first occurrence of this sum
    }
   }
   return len;




}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int ans= ksubarry(arr, n, k);
    cout << "Length of longest subarray with sum " << k << " is: " << ans << endl;
    return 0;
}


