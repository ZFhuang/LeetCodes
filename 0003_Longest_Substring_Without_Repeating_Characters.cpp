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

    //字符数组标记法,65.7%
    //遇到重复字符时将重复处之前的字符记录删去
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int max=0;
        int tail=0; //尾部标记
        int hashmap[128];
        //初始化赋值用memset，且memset只能按照字节赋值，也就是建议赋值0和-1
        //数组默认初始值是0
        //若初始化时列出的元素比较少，则只会初始化前面的部分
        memset(hashmap,-1,sizeof(int)*128);
        for(int i=0;i<s.size();i++){
            //只需要其最后出现的位置即可，不用记录为链表，会徒增麻烦
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

    //优化筛选算法,92.98%
    //利用最后一个重复串之后的串就可能是最长无重复串的特性
    int lengthOfLongestSubstring(string s) {
        vector<int>a(128, -1);
        //j是已出现的最后一个出现重复的字符的串中位置
        int j = 0, result = 0;
        for (int i = 0; i < s.length(); ++i) {
            //相当于用i和j将问题拆分为子串来处理
            //当目前字符在记录中出现时
            if (a[s[i]] != -1) {
                //中途结果取当前结果与当前位置减j的最大值
                //即求子串中的剩余串长是否比之前的最大串长长
                result = max(result, i - j);
                //将这个字符出现前出现的字符的记录重置为无
                for (; j <= a[s[i]]; ++j)
                    a[s[j]] = -1;
            }
            //记录此字符在字符串中的位置
            a[s[i]] = i;
        }
        //最终结果是中途结果（之前最大的串长）与字符串长度减j（最终的剩余串长）中的最大值
        result = max(result, int(s.length()) - j);
        return result;
    }
};
