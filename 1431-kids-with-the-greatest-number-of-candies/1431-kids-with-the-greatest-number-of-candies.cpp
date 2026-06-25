class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>dummy;
        int n=candies.size();
        int maxCandy = *max_element(candies.begin(), candies.end());
        //sort(candies.begin(),candies.end());
        for(int i=0;i<n;i++ ){
            if(candies[i]+extraCandies>=maxCandy){
                dummy.push_back(true);
            }
            else dummy.push_back(false);
        }
        return dummy;
    }
};