/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    
    //暴力解法,0.9%
    //双层循环比对每个数字对直到遍历出目标答案
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }    
            }
        }
        return {-1,-1};
    }
    
    
    
    //使用map的解法,59.8%
    vector<int> twoSum(vector<int>& nums, int target) {
        //由于数字不重复，先用一个循环将数字打入map（0桶排序）得到排序后的数据
        std::map<int,int> e;
        for(int i=0;i<nums.size();i++){
            e[nums[i]]=i;
        }
        //遍历每个数，利用目标数-当前数=另一个被加数的特性
        //查看是否能找到另一个被加数来返回
        //两数不能相同是防止遍历到1/2数时找到自己
        for(int i=0;i<nums.size();i++){
            if(e.count(target-nums[i])&&(e[target-nums[i]]!=i)){
                return {i,e[target-nums[i]]};
            }
        }
        return {-1,-1};
    }
    
    
    //使用unordered_map,96.5%
    //这是使用hashtable实现的，map是用红黑树实现的
    //多次查询时应该选用unordered_map，但单次查询时map可以确保良好的最坏情况运行时间
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            //当找不到时会返回m.end表示已寻找到结尾
            if(m.find(target - nums[i]) != m.end()){
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        //全程使用大括号（列表写法）来方便返回
        return {};
    }
};
