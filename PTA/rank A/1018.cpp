/*
大家应该都会玩“锤子剪刀布”的游戏.
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：
5 3 2
2 3 5
B B
*/

#include<iostream>
using namespace std;

// 0 fool, 1 A, 2 B
int whoWin(char A, char B) {
	if (A == B) {
		return 0;
	}
	if (A == 'C') {
		if (B == 'J') {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (A == 'J') {
		if (B == 'B') {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (A == 'B') {
		if (B == 'C') {
			return 1;
		}
		else {
			return 2;
		}
	}
}

int main() {
	int N;
	cin >> N;
	// B=0, C=1, J=2
	int WinA[3] = { 0 };
	int WinB[3] = { 0 };
	for (int i = 0; i < N; ++i) {
		char A, B;
		cin >> A >> B;
		if (whoWin(A, B) == 1) {
			if (A == 'B') {
				++WinA[0];
			}
			else if (A == 'C') {
				++WinA[1];
			}
			else {
				++WinA[2];
			}
		}
		else if (whoWin(A, B) == 2) {
			if (B == 'B') {
				++WinB[0];
			}
			else if (B == 'C') {
				++WinB[1];
			}
			else {
				++WinB[2];
			}
		}
	}

	// 1, 2
	int sumA = 0, sumB = 0, sumFool = 0;
	for (int i = 0; i < 3; ++i) {
		sumA += WinA[i];
		sumB += WinB[i];
	}
	sumFool = N - sumA - sumB;
	cout << sumA << " " << sumFool << " " << sumB << endl;
	cout << sumB << " " << sumFool << " " << sumA << endl;

	// 3
	int bestA = 0, bestB = 0, idxA = 0, idxB = 0;
	for (int i = 0; i < 3; ++i) {
		if (WinA[i] > bestA) {
			bestA = WinA[i];
			idxA = i;
		}
		if (WinB[i] > bestB) {
			bestB = WinB[i];
			idxB = i;
		}
	}
	// B=0, C=1, J=2
	if (idxA == 0) {
		cout << "B" << " ";
	}
	else if (idxA == 1) {
		cout << "C" << " ";
	}
	else if (idxA == 2) {
		cout << "J" << " ";
	}
	if (idxB == 0) {
		cout << "B";
	}
	else if (idxB == 1) {
		cout << "C";
	}
	else if (idxB == 2) {
		cout << "J";
	}

	return 0;
}