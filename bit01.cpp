#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int bintodec(string num){
    int two=1;
    int n = num.length();
    int ans = 0;
    for (int i = n-1; i>=0;--i){
        if(num[i]=='1') ans+=two;
        two *= 2;
    }
    return ans;
};
string dectobin(int num){
    string rem = "";
    while(num>0){
        rem += num % 2+'0';
        num = num / 2;
        
    }
    reverse(rem.begin(),rem.end());
    return rem;
}

int main(){
    // string num="1000";
    // int ans=bintodec(num);
    // cout << "The decimal form of the"<<" " << ans;
    
    int n = 88888;
    cout <<" The binary form of the decimal is"<< dectobin(n);
    return 0;
}

