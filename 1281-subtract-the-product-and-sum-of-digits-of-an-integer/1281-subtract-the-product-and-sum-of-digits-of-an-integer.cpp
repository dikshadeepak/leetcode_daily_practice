class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int s=0;
        int p=1;
        while(n!=0){
            int num=n%10;
            s=s+num;
            p=p*num;
            n=n/10;
        }
        int sol=p-s;
        return sol;
    }
};