class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            count=0;
            while(nums[i]){
                int a=nums[i]%10;
                count++;
                nums[i]=nums[i]/10;
            }
            if(count%2==0) ans++;
            
            
        }
        return ans;
    }
};