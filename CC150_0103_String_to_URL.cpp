/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

示例1:

 输入："Mr John Smith    ", 13
 输出："Mr%20John%20Smith"
示例2:

 输入："               ", 5
 输出："%20%20%20%20%20"
提示：

字符串长度在[0, 500000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-url-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //传统方法,82.3%
    //将改变后的字符串输入到新的数组中,记得结尾要附一个结束符
    string replaceSpaces(string S, int length) {
        //长度为目标字符串+1,省点内存
        char* newString = new char[S.size() + 1];
        int cursor = 0;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') {
                newString[cursor] = '%';
                newString[cursor + 1] = '2';
                newString[cursor + 2] = '0';
                cursor += 2;
            }
            else {
                newString[cursor] = S[i];
            }
            cursor++;
        }
        //结束符
        newString[cursor] = '\0';
        //string的指针构造
        //string(const char * s, size_type n)
        return string(newString, S.size() + 1);
    }

    //极致优化,100%
    //关闭流同步+使用字符串拼接
    string replaceSpaces(string S, int length) {
        //由于cin，cout与stdin总是保持同步的，所以有很大性能损失
        //此语句关闭流的同步加快cin和cout读取
        ios::sync_with_stdio(false);
        string str = "";
        for (int i = 0; i < length; i++) {
            //使用字符串拼接+=号的效率是最高的
            if (S[i] == ' ') str += "%20";
            else str += S[i];
        }
        return str;
    }
};