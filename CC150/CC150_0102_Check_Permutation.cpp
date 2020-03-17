/*
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //传统的数组打表法,100%
    //加入简单的预筛选加快速度
    bool CheckPermutation(string s1, string s2) {
        //两个数组，记得别忘了sizeof(int)
        int check1[128];
        memset(check1, 0, sizeof(int) * 128);
        int check2[128];
        memset(check2, 0, sizeof(int) * 128);
        //筛选
        if (s1.size() != s2.size())
            return false;
        //打表
        for (auto c : s1)
            check1[(int)c] += 1;
        for (auto c : s2)
            check2[(int)c] += 1;
        //逐位对比
        for (int i = 0; i < 128; i++)
            if (check1[i] != check2[i])
                return false;
        return true;
    }
};