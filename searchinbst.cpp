#include<bits/stdc++.h>
using namespace std;
int search(vector<int> &arr,int k){
    int low = 0;
    int high = arr.size() - 1;
    while(low<=high){
        int mid = low +(high-low) / 2;
        if(arr[mid]==k)
            return mid;
        //if the left part is sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k <=arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }    
        //if the right part is soretd
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    // if the array is not initailize the array with the index of the size 0 
    //the space complexity  and the  time complexity od t4 binary serach is
    //the time complexity of the log basse 2 of the n why because the array is eliminating  half for every increment of the two pointers if the low and the high 
    // the elimination not take any extra space so the space complexity  is 0(1)
    vector<int>arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int k = 3;
    int pos = search(arr, k);
    cout << pos << endl;
    
    return 0;
}  