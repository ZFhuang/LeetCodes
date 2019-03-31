/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

class Solution {
public:
    //暴力解法，58.8%
    string longestPalindrome(string s) {
        int max=0;
        int count=0;
        int left=0,sum=0;
        //快一点点
        int n=s.size();
        for(int i=0;i<n;i++){
            if((n-i)<(max/2)){
                break;
            }
            //center
            count=0;
            for(int j=1;j<n;j++){
                if(i-j<0||i+j>n||s[i-j]!=s[i+j]){
                    break;
                }
                else{
                    count++;
                }
            }
            if(count*2+1>max){
                max=count*2+1;
                left=i-count;
                sum=count*2+1;
            }
            
            //left
            count=0;
            for(int j=1;j<n;j++){
                if(i-j+1<0||i+j>n||s[i-j+1]!=s[i+j]){
                    break;
                }
                else{
                    count++;
                }
            }
            if(count*2>max){
                max=count*2;
                left=i-count+1;
                sum=count*2;
            }
        }
        //最后再来计算
        return s.substr(left,sum);
    }
};
