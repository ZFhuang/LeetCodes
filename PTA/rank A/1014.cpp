/*
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

输出样例：
THU 14:04
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	int time[3] = { 0 };

	// 第一个字符串
	bool flag = false;
	int count = 0;
	auto iter1 = A1.cbegin();
	auto iter2 = A2.cbegin();
	while (iter1 != A1.cend() && iter2 != A2.cend()) {
		if (*iter1 == *iter2) {
			// 日期, 注意日期仅仅从A到G
			if (flag == false && *iter1 >= 'A' && *iter1 <= 'G') {
				time[0] = *iter1 - 'A';
				flag = true;
			}
			// 小时, 当日期得到后才开始计数
			if (flag) {
				if (*iter1 >= '0' && *iter1 <= '9') {
					if (count == 1) {
						time[1] = *iter1 - '0';
					}
					++count;
				}
				else if (*iter1 >= 'A' && *iter1 <= 'N') {
					if (count == 1) {
						time[1] = *iter1 - 'A' + 10;
					}
					++count;
				}
			}
			if (count > 1 && flag) {
				break;
			}
		}
		iter1++;
		iter2++;
	}

	// 第二个字符串
	count = 0;
	iter1 = B1.cbegin();
	iter2 = B2.cbegin();
	while (iter1 != B1.cend() && iter2 != B2.cend()) {
		if (*iter1 == *iter2) {
			if ((*iter1 >= 'A' && *iter1 <= 'Z') || (*iter1 >= 'a' && *iter1 <= 'z')) {
				time[2] = count;
				break;
			}
		}
		iter1++;
		iter2++;
		++count;
	}

	// 日期
	switch (time[0])
	{
	case 0:
		cout << "MON ";
		break;
	case 1:
		cout << "TUE ";
		break;
	case 2:
		cout << "WED ";
		break;
	case 3:
		cout << "THU ";
		break;
	case 4:
		cout << "FRI ";
		break;
	case 5:
		cout << "SAT ";
		break;
	case 6:
		cout << "SUN ";
		break;
	}

	// 时间, 注意要补零
	if (time[1] < 10) {
		cout << "0" << time[1] << ":";
	}
	else {
		cout << time[1] << ":";
	}
	if (time[2] < 10) {
		cout << "0" << time[2];
	}
	else {
		cout << time[2];
	}
	return 0;
}