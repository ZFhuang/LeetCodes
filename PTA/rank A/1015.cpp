/*
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

// 储存学生信息的结构
class Data {
public:
	// 记得写构造函数
	Data(string id, int de, int cai) {
		this->id = id;
		this->de = de;
		this->cai = cai;
	}
	string id;
	int de;
	int cai;
};

// 自定义几个排序器
bool idSmaller(const Data& a, const Data& b) {
	// 注意id的排序顺序是相反的
	return a.id < b.id;
}

bool deLarger(const Data& a, const Data& b) {
	return a.de > b.de;
}

bool sumLarger(const Data& a, const Data& b) {
	return (a.de + a.cai) > (b.de + b.cai);
}

int main() {
	// 优化大量数据的输入输出防止超时
	static auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

	int N, L, H;
	cin >> N >> L >> H;
	list<Data> list[4];
	int count = 0;

	// partition
	while (N--)
	{
		string id;
		int de;
		int cai;
		cin >> id >> de >> cai;
		if (de >= L && cai >= L) {
			++count;
			if (cai >= H && de >= H) {
				list[0].emplace_back(id, de, cai);
			}
			else if (cai < H && de >= H) {
				list[1].emplace_back(id, de, cai);
			}
			else if (cai < H && de < H && de >= cai) {
				list[2].emplace_back(id, de, cai);
			}
			else {
				list[3].emplace_back(id, de, cai);
			}
		}
	}

	// sort
	for (int i = 0; i < 4; ++i) {
		// 用list的成员函数来排序
		list[i].sort(idSmaller);
		list[i].sort(deLarger);
		list[i].sort(sumLarger);
		// 下面的写法由于stl的sort不支持非随机访问的容器，所以不能编译通过(尽管VS的编译器可以处理)
		//stable_sort(list[i].begin(), list[i].end(), idSmaller);
		//stable_sort(list[i].begin(), list[i].end(), deLarger);
		//stable_sort(list[i].begin(), list[i].end(), sumLarger);
	}

	// output
	cout << count << endl;
	for (int i = 0; i < 4; ++i) {
		auto iter = list[i].cbegin();
		while (iter != list[i].cend())
		{
			cout << iter->id << " " << iter->de << " " << iter->cai << endl;
			++iter;
		}
	}

	return 0;
}