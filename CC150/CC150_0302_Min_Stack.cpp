/*
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

示例：

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
	//使用现有的STL容器vector,6.0%,212ms
	//主要问题是min操作的时间复杂度是O(n)
public:
	MinStack() {
	}

	void push(int x) {
		stack.push_back(x);
	}

	void pop() {
		if (stack.empty()) {
			return;
		}
		stack.pop_back();
	}

	int top() {
		if (stack.empty()) {
			return NULL;
		}
		return stack.back();
	}

	int getMin() {
		//遍历一次栈
		if (stack.empty()) {
			return NULL;
		}
		int min = stack.back();
		for (auto i : stack) {
			if (i < min) {
				min = i;
			}
		}
		return min;
	}

private:
	vector<int> stack;

	//自定义类型使用现有的STL容器vector,93.2%,24ms
	//让每个元素都记录下自己以下的栈的最小值，这样可以在O(1)中得到最小值
public:
	struct StackElement {
		int value;
		//每个子栈的最小值保存在元素内
		int min;
		StackElement(int v, int m) {
			value = v;
			min = m;
		}
	};

	MinStack() {
	}

	void push(int x) {
		if (!stack.empty()) {
			//push时需要判断是否需要更新当前最小值
			if (x <= stack.back()->min) {
				//更新
				stack.push_back(new StackElement(x, x));
			}
			else {
				stack.push_back(new StackElement(x, stack.back()->min));
			}
		}
		else {
			stack.push_back(new StackElement(x, x));
		}

	}

	void pop() {
		if (stack.empty()) {
			return;
		}
		stack.pop_back();
	}

	int top() {
		if (stack.empty()) {
			return NULL;
		}
		return stack.back()->value;
	}

	int getMin() {
		if (stack.empty()) {
			return NULL;
		}
		//可以直接返回最小值
		return stack.back()->min;
	}

private:
	//注意new得到的是指针，所以为了vector方便也只存放指针
	vector<StackElement*> stack;

	//将最小值栈划分开来且直接使用容器stack，93.2%,24ms
	//将最小值用一个另外的栈来保存，节省点内存也避免了新数据结构的定义
public:
	stack<int> s;
	stack<int> buf;//最小值栈

	MinStack() {
		buf.push(INT_MAX);
	}

	void push(int x) {
		//压入时要注意是否需要刷新
		if (x <= buf.top()) {
			buf.push(x);
		}
		s.push(x);
	}

	void pop() {
		//当当前弹出的值等于当前栈的最小值时弹出最小值栈
		//由于两个栈保持着顺序的稳定所以可以这样
		if (s.top() == buf.top())
			buf.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return buf.top();
	}
};