/*
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7

输出样例：
17636684150141093474 3
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string A, result;
	int B;
	cin >> A >> B;
	auto iter = A.cbegin();
	int buf = 0;
	// 计数器
	int time = 0;
	while (iter != A.cend()) {
		buf += *iter - '0';
		// 被除数是0
		if (buf == 0) {
			result.push_back('0');
			time = 0;
		}
		// 正常
		if (buf / B > 0) {
			result.push_back((buf / B) + '0');
			// 得到新的被除数
			buf = buf % B;
			time = 0;;
		}
		// 更新被除数
		buf *= 10;
		++time;
		// 当跳过两个数时需要强制输出一个0
		if (time == 2) {
			result.push_back('0');
			time = 0;
		}
		++iter;
	}
	// 特殊情况，商为0
	if (result.size() == 0) {
		result = "0";
	}
	// 别忘了余数
	cout << result << " " << buf / 10;
	return 0;
}