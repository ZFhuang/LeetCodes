/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

class Solution {
public:
    //97.96%
    string longestCommonPrefix(vector<string>& strs) {
    //暴力解决，只是需要判断些有的没的
        if(strs.empty()){
            return "";
        }
        int p=0;
        int len=strs[0].size();
        int num=strs.size();
        if(num==1){
            return strs[0];
        }
        for(int i=0;i<num;i++){
            if(strs[i].size()<len){
                len=strs[i].size();
            }  
        }
        if(len==0){
            return "";
        }
        char *ret=new char[len+1];
        while(true){
            if(p>=len){
                break;
            }
            char now=(strs[0])[p];
            for(int i=1;i<num;i++){
                if((strs[i])[p]!=now){
                     ret[p]='\0';
                    return (string)ret;
                }
            }
            ret[p]=now;
            p++;
        }
        ret[p]='\0';
        return (string)ret;
    }
};
