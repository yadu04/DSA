#include<iostream>  
#include<vector>
#include<algorithm>
#include<climits> // For INT_MIN
#include<cmath> // For abs function
// print the maximum subarray
using namespace std;
vector<int>maxsubarray(vector<int> &nums){
    int sum=0;
    long long maxi=INT_MIN;
    int start=0;
    int ans_start=0, ans_end=0;
    for(int i=0;i<nums.size();i++){ 
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
            ans_start=start;
            ans_end=i;
        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    return {ans_start, ans_end}; // Return the indices of the maximum subarray
    // cout << "Maximum subarray sum is: " << maxi << endl; // Output the maximum subarray sum
    // cout << "Subarray indices: [" << ans_start << ", " << ans_end    << "]" << endl; // Output the indices of the maximum subarray
    // return maxi; // Return the maximum subarray sum  
}
int main(){
   vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
   vector<int>result=maxsubarray(nums); 
   int ans_start = result[0];
   int ans_end = result[1];
   int max_sum = 0;
   for (int i = ans_start; i <= ans_end; ++i) {
       max_sum += nums[i];
   }
   cout << "Maximum subarray sum is: " << max_sum << endl;
   cout << "Subarray indices: [" << ans_start << ", " << ans_end << "]" << endl;
   return 0;

}