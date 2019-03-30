/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    //暴力解法,0.9%
    /*vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }    
            }
        }
        return {-1,-1};
    }
    */
    
    //使用map的解法,59.8%
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> e;
        for(int i=0;i<nums.size();i++){
            e[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(e.count(target-nums[i])&&(e[target-nums[i]]!=i)){
                return {i,e[target-nums[i]]};
            }
        }
        return {-1,-1};
    }
};
