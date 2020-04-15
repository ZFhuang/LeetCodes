/*
一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即最后M个数循环移至最前面的M个位置。
如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6

输出样例:
5 6 1 2 3 4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 通过全逆序，分段两次逆序可以完成，LeetCode出现过
int main() {
	int num;
	cin >> num;
	vector<int> inp(num);
	int cnt;
	cin >> cnt;
	// 注意处理特殊情况
	if (cnt > num)
		cnt -= num;
	for (int i = 0; i < num; ++i) {
		int tmp;
		cin >> tmp;
		inp[i] = tmp;
	}
	reverse(inp.begin(), inp.end());
	reverse(inp.begin(), inp.begin() + cnt);
	reverse(inp.begin() + cnt, inp.end());
	for (int i = 0; i < num; ++i) {
		cout << inp[i];
		if (i != num - 1) {
			cout << " ";
		}
	}
}