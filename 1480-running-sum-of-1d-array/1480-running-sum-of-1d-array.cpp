class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        

        vector<int>dummy;
        for( int i=0;i<nums.size();i++){
          if(i==0) dummy.push_back(nums[0]);
          else {
            nums[i]=nums[i]+nums[i-1];
            dummy.push_back(nums[i]);
          }
        }
       return dummy;
    }
};