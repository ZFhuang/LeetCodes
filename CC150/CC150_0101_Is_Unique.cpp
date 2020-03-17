/*
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：

输入: s = "leetcode"
输出: false
示例 2：

输入: s = "abc"
输出: true
限制：

0 <= len(s) <= 100
如果你不使用额外的数据结构，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-unique-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //使用标记数组,66.6%
    //遇到标记则直接返回，没出现的字符则设置标记
    bool isUnique(string astr) {
        int unique[128];
        //leetcode需要重置数组适应多组数据
        memset(unique, 0, sizeof(int) * 128);
        for (char& c : astr) {
            if (unique[c] == 1)
                return false;
            else
                unique[c] = 1;
        }
        return true;
    }

    //不使用额外的数据结构, 60.6%
    //用位运算来代替数组，测试（问面试官）得知字符来自a-z
    bool isUnique(string astr) {
        //用int来标识字母情况
        int unique = 0;
        int mask;
        for (char& c : astr) {
            //移位制造掩码
            mask = 1 << (c - 'a');
            if (unique & mask)
                return false;
            else
                unique |= mask;
        }
        return true;
    }
};