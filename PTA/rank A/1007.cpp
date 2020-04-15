/*
让我们定义dn为：dn=p(n+1)−p(n)，其中p(i)是第i个素数。显然有d1=1，且对于n>1有dn是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20

输出样例:
4
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 素数筛法，大数字下发生段错误
int main() {
	int N;
	cin >> N;
	bool *prime = new bool[N+1];
	vector<int> vec={1};
	for (int i = 2; i < N+1; ++i) {
		if (prime[i] == false) {
			for (int j = 2; j < N; ++j) {
				if (i * j <= N) {
					prime[i * j] = true;
				}
			}
			vec.push_back(i);
		}
	}

	int count=0;
	for (int i = vec.size()-1; i >= 0; --i) {
		if (vec[i] - vec[i - 1] == 2) {
			++count;
		}
	}
	cout << count;
}

// 传统暴力法
bool isprime(int a) {
	// 注意这里运行到sqrt(a)即可
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0) return false;
	return true;
}
int main() {
	int N, cnt = 0;
	cin >> N;
	for (int i = 5; i <= N; i++)
		if (isprime(i - 2) && isprime(i)) cnt++;
	cout << cnt;
	return 0;
}