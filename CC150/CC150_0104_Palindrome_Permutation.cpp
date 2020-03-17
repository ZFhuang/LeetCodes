/*
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //奇偶计数法,100%
    //字符串为偶数时，必然不能出现奇数个字符
    //字符串为奇数时，可以出现一次奇数字符
    bool canPermutePalindrome(string s) {
        int valid[128];
        memset(valid, 0, sizeof(int) * 128);
        //计数
        for (auto c : s) {
            valid[c] += 1;
        }
        int odds = 0;
        int sOdds = s.size() % 2;
        for (int i = 0; i < 128; i++) {
            //奇数个字符
            if (valid[i] % 2 == 1) {
                odds++;
            }
            if (sOdds) {
                //字符串奇数
                if (odds > 1)
                    return false;
            }
            else {
                //字符串偶数
                if (odds > 0)
                    return false;
            }
        }
        return true;
    }
};