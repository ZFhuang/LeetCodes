/*
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
A1 = 能被 5 整除的数字中所有偶数的和；
A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n​2+n3−n​4...；
A3 = 被 5 除后余 2 的数字的个数；
A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5 = 被 5 除后余 4 的数字中最大数字。

输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A1~A5 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例 1：
30 11 2 9.7 9

输入样例 2：
8 1 2 4 5 6 7 9 16

输出样例 2：
N 11 2 N 9
*/

#include<iostream>
#include<vector>
/*
io`manip(ulator(操纵器))
控制符	                        作用
setbase(n)	                    设置整数为n进制(n = 8, 10, 16)
setfill(n)	                    设置字符填充，c可以是字符常或字符变量
setprecision(n)	                设置浮点数的有效数字为n位
setw(n)	                        设置字段宽度为n位
setiosflags(ios::fixed)	        设置浮点数以固定的小数位数显示
setiosflags(ios::scientific)	设置浮点数以科学计数法表示
setiosflags(ios::left)	        输出左对齐
setiosflags(ios::right)	        输出右对齐
setiosflags(ios::skipws)        忽略前导空格
*/
#include <iomanip>
#include<cstring>
using namespace std;

int main() {
	// 注意函数体中的变量不会进行值初始化，需要手动进行
	int num = 0, tmp = 0;
	double A[5];
	memset(A, 0, sizeof(double) * 5);
	// 也可以用double A[5]={0};
	int f[5];
	memset(f, 0, sizeof(int) * 5);
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> tmp;
		if (tmp % 5 == 0 && tmp % 2 == 0) {
			A[0] += tmp;
			++f[0];
		}
		if (tmp % 5 == 1) {
			if (f[1] % 2 == 0) {
				A[1] += tmp;
			}
			else {
				A[1] -= tmp;
			}
			++f[1];
		}
		if (tmp % 5 == 2) {
			A[2] += 1;
			++f[2];
		}
		if (tmp % 5 == 3) {
			A[3] += tmp;
			++f[3];
		}
		if (tmp % 5 == 4) {
			if (tmp >= A[4]) {
				A[4] = tmp;
				++f[4];
			}
		}
	}
	if (f[3] > 0) {
		A[3] /= f[3];
	}

	for (int i = 0; i < 5; ++i) {
		if (f[i] > 0) {
			if (i == 3) {
				// 控制小数为一位，函数在<iomanip>中
				cout << fixed << setprecision(1);
				cout << A[i];
				cout << fixed << setprecision(0);
			}
			else {
				cout << A[i];
			}
		}
		else {
			cout << "N";
		}
		if (i != 4) {
			cout << " ";
		}
	}
	return 0;
}