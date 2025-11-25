class Solution {
public:
    int reverse(int x) {
        long rev=0; // it is declared long to handle overflow
        int digit;
        while(x!=0){
            digit=x%10; 
            rev=rev*10+digit;
            if(rev>INT_MAX || rev<INT_MIN) // checking overflow condition
            return 0;
            x=x/10;
        }
        return rev;
    }
};