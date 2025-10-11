#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct  Item{
    int val;
    int weight;
};
class Solution{
    public:
    bool static com(Item a,Item b){
        int r1 = (double) a.val / (double)a.weight;
        int r2 = (double) b.val / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W,Item arr[],int n){
        int currentwe=0;
        double finalval=0.0;
        for (int i = 0; i < n;i++){
            if((currentwe+arr[i].weight) <= W){
                finalval += (double)arr[i].val;
                currentwe += arr[i].weight;
            }
            else {
                int rem=W-arr[i].weight;
                finalval += (double)arr[i].val * ((double)rem / (double)arr[i].weight);
                break;
            }
        }
        return finalval;
    }
};

int main(){

int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}