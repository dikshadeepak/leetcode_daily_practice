/*class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int largest = nums[nums.size() - 1];
        int count = 1;

        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] != largest) {
                largest = nums[i];
                count++;
            }

            if(count == 3)
                return largest;
        }

        return nums[nums.size() - 1];
    }
};*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(int x : nums) {
            if(x == first || x == second || x == third)
                continue;

            if(x > first) {
                third = second;
                second = first;
                first = x;
            }
            else if(x > second) {
                third = second;
                second = x;
            }
            else if(x > third) {
                third = x;
            }
        }

        if(third == LLONG_MIN)
            return first;

        return third;
    }
};