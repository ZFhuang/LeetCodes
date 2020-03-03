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
	//最原始暴力的检测子串,98.3%，4ms
	//由于调用了n次判断子串，O(n2)的复杂度，非常慢
	//但是由于Leetcode的样例库不大所以速度还是快
	//旋转后的串拼接，若原串可在拼接串找到，则存在
	bool isFlipedString(string s1, string s2) {
		//加速
		static auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

		if (s1.size() != s2.size())
			return false;
		if (s1.size() < 2)
			return true;
		//先把旋转后的串拼接
		//由于s1=xy,s2=yx; => s2s2=yxyx => s2s2= ys1x
		//检测是否存在
		string s = s2 + s2;
		//记得缩小搜索范围
		for (int i = 0; i < s.size() - s1.size(); ++i) {
			if (checkSame(s1, s, i))
				return true;
		}
		return false;
	}
	//暴力检测，非常慢，调用函数时记得使用常量引用来避免拷贝构造以加速
	bool checkSame(const string& s1, const string& s, int start) {
		for (int i = start; i < start + s1.size(); ++i) {
			if (s[i] != s1[i - start]) {
				return false;
			}
		}
		return true;
	}

	//不调用内部函数但进行内部匹配，92.1%,8ms
	//进行字符串匹配，使用KMP算法
	//KMP算法来自：
	//如何更好的理解和掌握 KMP 算法? - 海纳的回答 - 知乎
	​//https://www.zhihu.com/question/21923021/answer/281346746
		bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		if (s1.size() < 2)
			return true;
		int length = s1.size();
		//拼接
		string s = s2 + s2;
		int length2 = s.size();
		int* next = new int[length];
		memset(next, 0, sizeof(int) * length);
		next[0] = -1;
		//得到next数组，相当于自己作为自己的匹配串
		//被匹配串比匹配串前进一位
		//i是被匹配的，j是匹配的，所以j指针会回退，i不会
		int j = -1, i = 0;
		while (i < length - 1)
		{
			//匹配串的串头或检测到相同的字符
			if (j == -1 || s1[i] == s1[j]) {
				//匹配串和被匹配串指针都前进
				//j是匹配的字符个数
				++i; ++j;
				//记录当前自己被匹配的进度，记录为匹配的个数
				next[i] = j;
			}
			else {
				//失配时相当于回到之前字符串出现内重复的部分再次尝试
				//所以匹配个数j也会回退
				j = next[j];
			}
		}
		//具体匹配阶段
		i = 0;
		j = 0;
		//next=0代表此字符失配时回到0号位置，next=-1时则会后移
		while (j < length && i < length2)
		{
			//相同时指针一同前进
			if (j == -1 || s[i] == s1[j]) {
				++i; ++j;
			}
			//失配时j指针回到之前上次重复匹配的位置
			else {
				j = next[j];
			}
		}

		//若匹配串j到达终点表示有出现完全匹配的部分
		//此时实际匹配的位置为i-j，即匹配的开始位置
		if (j == length)
			return true;
		else
			return false;
	}

	//调用内部函数来搜索,98.3%,4ms
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		if (s1.empty()) return true;
		//string::npos指size_t的最大值，通常标识不存在
		return (s1 + s1).find(s2) != string::npos;
	}
};