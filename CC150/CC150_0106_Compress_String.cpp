/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//传统的读取计数压入,90.1%
	//先压入首次出现的字符，再计数，然后压入最终数字，进入下次循环
	string compressString(string S) {
		//长度小于3的字符串必然无法压缩，直接返回
		if (S.size() < 3) {
			return S;
		}

		int old = S.size();
		string retS;
		char last;
		int count = 1;
		//第一次压入
		last = S[0];
		retS += last;
		for (int i = 1; i < old; ++i) {
			//相同时技术
			if (last == S[i]) {
				++count;
			}
			else {
				//用C11以后的自带函数to_string将数字转为字符串
				//to_string效率低于sprintf但是也很高
				retS += to_string(count);
				count = 1;
				last = S[i];
				retS += last;
			}
		}
		retS += to_string(count);
		//最后比较长度并返回
		if (retS.size() < old) {
			return retS;
		}
		else {
			return S;
		}
	}

	//优化了压入字符串速度的写法,100%
	//用字符串模板流ostringstream加速构造
	string compressString(string S) {
		//LeetCode常用的加速读写语句
		//Lambda表达式，先关闭cincout同步，使cincout不经过缓冲区加速
		//接触cin与cout的绑定
		//这样写是加速了LeetCode自身评审时的速度
		static auto speedup = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
		//直接返回
		if (S == "") return "";
		char last = S[0];
		int nCount = 1;
		string str = "";
		//字符串模板类，会动态分配内存
		//动态申请适合大小的内存，既满足了内存节省又满足了空间局部性
		ostringstream ss;
		//循环扫描字符串
		for (int i = 1; i < S.size(); ++i) {
			//重复字符时
			if (S[i] == last) { ++nCount; continue; }
			//将内容输入ss
			ss << last << nCount;
			nCount = 1;
			last = S[i];
		}
		ss << last << nCount;
		//最后从ss中得到所需的字符串
		str = ss.str();
		//返回较短者
		return str.size() < S.size() ? str : S;
	}
};