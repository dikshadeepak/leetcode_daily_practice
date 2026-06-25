class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
    
        vector<int> arr;
        while (i<n){
          arr.push_back(nums[i]);
          arr.push_back(nums[i+n]);
          i++;
          
        }
        return arr;
    }
};