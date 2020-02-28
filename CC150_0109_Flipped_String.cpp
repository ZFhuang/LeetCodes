/*
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

示例1:

 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:

 输入：s1 = "aa", "aba"
 输出：False
提示：

字符串长度在[0, 100000]范围内。
说明:

你能只调用一次检查子串的方法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flipped-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//最原始暴力的检测子串,5.4%，1200ms
	//由于调用了n次判断子串，O(n2)的复杂度，非常慢
	//旋转后的串拼接，若原串可在拼接串找到，则存在
	bool isFlipedString(string s1, string s2) {
		static auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

		if (s1.size() != s2.size())
			return false;
		if (s1.size() < 2)
			return true;
		//先把旋转后的串拼接
		//由于s1=xy,s2=yx; => s2s2=yxyx => s2s2= ys1x
		//检测是否存在
		string s = s2 + s2;
		for (int i = 0; i < s.size(); ++i) {
			if (checkSame(s1, s, i))
				return true;
		}
		return false;
	}
	//暴力检测，非常慢
	bool checkSame(string s1, string s, int start) {
		for (int i = start; i < start + s1.size(); ++i) {
			if (s[i] != s1[i - start]) {
				return false;
			}
		}
		return true;
	}

	//不调用内部函数但进行内部匹配，92.1%,8ms
	//进行字符串匹配，使用KMP算法
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		if (s1.size() < 2)
			return true;
		int length = s1.size();
		string s = s2 + s2;
		int length2 = s.size();
		int* next = new int[length];
		memset(next, 0, sizeof(int) * length);
		next[0] = -1;
		int j = -1, i = 0;
		//得到next数组
		while (i < length - 1)
		{
			if (j == -1 || s1[i] == s1[j]) {
				++i; ++j;
				next[i] = j;
			}
			else {
				j = next[j];
			}
		}
		//具体得到匹配位置
		i = 0;
		j = 0;
		while (j < length && i < length2)
		{
			if (j == -1 || s[i] == s1[j]) {
				++i; ++j;
			}
			else {
				j = next[j];
			}
		}

		if (j == length)
			return true;
		else
			return false;
	}

	//调用内部函数来搜索,98.33%,4ms
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		if (s1.empty()) return true;
		//string::npos指size_t的最大值，通常标识不存在
		return (s1 + s1).find(s2) != string::npos;
	}
};