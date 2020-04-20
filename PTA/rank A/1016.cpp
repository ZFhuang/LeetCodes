/*
正整数 A 的“DA（为 1 位整数）部分”定义为由 A 中所有 DA 组成的新整数 PA。例如：给定 A=3862767，DA =6，则 A 的“6 部分”PA 是 66，因为 A 中有 2 个 6。
现给定 A、DA、B、DB，请编写程序计算 PA+PB 。

输入格式：
输入在一行中依次给出 A、DA、B、DB，中间以空格分隔，其中 0<A,B<10^10 。

输出格式：
在一行中输出 PA+PB 的值。

输入样例 1：
3862767 6 13530293 3

输出样例 1：
399

输入样例 2：
3862767 1 13530293 8

输出样例 2：
0
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string A, B, DA, DB;
	cin >> A >> DA >> B >> DB;
	int SA = 0, SB = 0;
	auto iter = A.cbegin();
	while (iter != A.cend())
	{
		// 记录值
		if (*iter == DA[0]) {
			SA *= 10;
			SA += *iter - '0';
		}
		++iter;
	}
	iter = B.cbegin();
	while (iter != B.cend())
	{
		if (*iter == DB[0]) {
			SB *= 10;
			SB += *iter - '0';
		}
		++iter;
	}

	cout << SA + SB;
	return 0;
}