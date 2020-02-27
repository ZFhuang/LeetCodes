/*
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入:
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入:
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //传统的指针同位扫描,51.5%
    //即允许一个字符的出错，长度不同时指针往后错一位
    bool oneEditAway(string first, string second) {
        //注意size返回值是size_t，是无符号数
        //因此需要+1比较
        //当长度差距在两字符以上则false，因为此时无法通过一次编辑来改正
        if ((first.size() + 1 > (second.size() + 2)) || (first.size() + 1 < (second.size())))
            return false;

        int cur1 = 0, cur2 = 0;
        bool flag = false;
        while (cur1 < first.size() && cur2 < second.size()) {
            //当前位是否相同
            if (first[cur1] != second[cur2]) {
                //出现过一次错误就false
                if (flag)
                    return false;
                else {
                    flag = true;
                    //替换，比较下一位是否相同或没有下一位了，相同才能继续，否则false
                    if (first.size() == second.size()) {
                        if (((cur1 + 1) != first.size()) && first[cur1 + 1] != second[cur2 + 1])
                            return false;
                    }
                    //插入或删除，比较长的那一边的下一位是否与短的当前位相同，相同才继续
                    else if (first.size() > second.size()) {
                        if (((cur1 + 1) != first.size()) && first[cur1 + 1] != second[cur2])
                            return false;
                        else {
                            ++cur1;
                            continue;
                        }
                    }
                    else if (first.size() < second.size()) {
                        if (((cur2 + 1) != second.size()) && second[cur2 + 1] != first[cur1])
                            return false;
                        else {
                            ++cur2;
                            continue;
                        }
                    }
                }
            }
            //移动指针
            ++cur1;
            ++cur2;
        }
        return true;
    }

    //在一次检测中判断三种情况,89.1%
    //提前通过交换固定住长串和短串相对位置，实现了代码复用并减少了判断次数和复杂性
    bool oneEditAway(string first, string second) {
        int len1 = first.size();
        int len2 = second.size();

        //判断各自长度，将长的字符串放到second的位置
        //长度也要记得交换
        //这一步将插入与删除统一了，因为删除交换后相当于对方的插入
        if (len1 > len2) {
            string t = first;
            first = second;
            second = t;

            int len = len1;
            len1 = len2;
            len2 = len;
        }

        //当长的字符串大于短的超过1，说明一次编辑无法实现
        if (len2 - len1 > 1) {
            return false;
        }

        //错误标记，最多只能发生一次错误所以用bool
        bool state = false;
        //主循环，循环初始化两个指针而循环短字符串到头时结束
        //循环时固定增加的时长字符串的指针因为插入必然发生在长字符串中
        for (int i1 = 0, i2 = 0; i1 < len1; i2++) {
            //发生同字符时
            if (first[i1] != second[i2]) {
                if (state) {
                    return false;
                }
                else {
                    state = true;
                    //原本是花哨的写法，这里我加了些括号
                    //其实就是若长串比较长(长度不是相等)，则短串指针暂停前移一循环，标志插入或删除了
                    //若长度相等，则正常前移，标志发生的是替换
                    //而对于下一位的正确与否交予下一个循环负责
                    i1 += ((len2 - len1) == 1 ? 0 : 1);
                }
            }
            //都相同时，默认也让短串前进
            else {
                i1++;
            }
        }
        return true;
    }
};