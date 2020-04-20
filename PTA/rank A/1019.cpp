/*
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10^4) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。

输入样例 1：
6767

输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

输入样例 2：
2222

输出样例 2：
2222 - 2222 = 0000
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 运行超时，但是找不到原因
// 不超时的版本可以参照:https://blog.csdn.net/u010889616/article/details/50173989
int main() {
	// 优化大量的输入输出
	static auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

	string S;
	cin >> S;
	int res = 0;

	while (true) {
		if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3]) {
			cout << S << " - " << S << " = 0000";
			return 0;
		}

		string sa = S;
		sort(sa.begin(), sa.end());
		string sb = S;
		reverse(sa.begin(), sa.end());

		int a = stoi(sa);
		int b = stoi(sb);

		res = a - b;
		S = to_string(res);

		cout << sa[0] << sa[1] << sa[2] << sa[3] << " - " << sb[0] << sb[1] << sb[2] << sb[3] << " = " << S[0] << S[1] << S[2] << S[3] << endl;
		if (res == 6174) {
			break;
		}
	}
	return 0;
}