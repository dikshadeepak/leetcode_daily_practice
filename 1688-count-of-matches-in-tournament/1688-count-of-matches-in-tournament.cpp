class Solution {
public:
    int numberOfMatches(int n) {
        int teams=n;
        int matches;
        int adv;
        int ans=0;
        while(teams>1){
            matches=teams/2;
            adv=teams-matches;
            teams=adv;
            ans=ans+matches;

        }
        return ans;
    }
};