/*
令 Pi 表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 PM 到 PN 的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 PM 到 P​N 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<iostream>
using namespace std;

bool isPrime(int tar) {
	if (tar == 1 || tar == 2) {
		return true;
	}
	for (int i = 2; i * i <= tar + 1; ++i) {
		if (tar % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int M, N;
	cin >> M >> N;
	int line = 0;
	int count = 0;
	for (int i = 1; true; ++i) {
		if (isPrime(i)) {
			++count;
			if (count > M) {
				cout << i;
				++line;
				if (line > 9) {
					if (count > N) {
						break;
					}
					cout << endl;
					line = 0;
				}
				else {
					if (count > N) {
						break;
					}
					cout << " ";
				}
			}
		}
	}
	return 0;
}