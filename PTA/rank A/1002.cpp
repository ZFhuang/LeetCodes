/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789

输出样例：
yi san wu
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string input;
    string output;
    int out = 0;
    cin >> input;
    // 编程规范点，用unsigned
    for (unsigned i = 0; i < input.size(); ++i) {
        out += input[i] - '0';
    }
    string ostring = to_string(out);
    for (unsigned i = 0; i < ostring.size(); ++i) {
        switch (ostring[i] - '0')
        {
        case 0:
            output += "ling ";
            break;
        case 1:
            output += "yi ";
            break;
        case 2:
            output += "er ";
            break;
        case 3:
            output += "san ";
            break;
        case 4:
            output += "si ";
            break;
        case 5:
            output += "wu ";
            break;
        case 6:
            output += "liu ";
            break;
        case 7:
            output += "qi ";
            break;
        case 8:
            output += "ba ";
            break;
        case 9:
            output += "jiu ";
            break;
        default:
            break;
        }
    }
    // 删去最后一个字符
    output.erase(output.end() - 1);
    cout << output << endl;
}