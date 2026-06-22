class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int revnum=0;
        int originalnum=x;
        while(x!=0){
            int num=x%10;
            if(revnum > INT_MAX / 10 || revnum < INT_MIN /10)
            return 0;
            revnum=revnum*10+num;
            x=x/10;

        }
        if(revnum==originalnum) return true;
        else  return false;
    

    }
};