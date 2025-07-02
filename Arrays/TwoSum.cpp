// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Language: C++

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=0;
        int sum=0;
        vector<int> result={0,0};
        for(i=0;i<(nums.size()-1);i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                sum=nums[i]+nums[j];
                if(sum == target)
                {
                    result[0]=i;
                    result[1]=j;
                }
                sum=0;
            }
        }
        return result;
    }
};