#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abcde";
    for(int i=0;i<s.length();++i){
         string temp=s.substr(0)+s.substr(0,i);
    cout<<temp<<endl;
    }

    return 0;

}