/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int max=0;
        int tail=0; //尾部标记
        int hashmap[128];
        //初始化赋值用memset，且memset只能按照字节赋值，也就是建议赋值0和-1
        //数组初始值是0
        //若初始化时列出的元素比较少，则只会初始化前面的部分
        memset(hashmap,-1,sizeof(int)*128);
        for(int i=0;i<s.size();i++){
            if(hashmap[(int)(s[i])]<tail){
                //记录元素的最后出现位置
                hashmap[(int)(s[i])]=i;
                count++;
            }else{
                if(count>max){
                    max=count;
                }
                //当遇到新的元素时更新尾部位置并计算子串长度
                tail=hashmap[(int)(s[i])]+1;
                hashmap[(int)(s[i])]=i;
                count=i-tail+1;
            }
        }
        if(count>max){
            max=count;
        }
        return max;
    }
};
