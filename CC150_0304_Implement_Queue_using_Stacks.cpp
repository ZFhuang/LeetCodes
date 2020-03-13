/*
实现一个MyQueue类，该类用两个栈来实现一个队列。

示例：
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明：
你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
	//传统的双栈，进行了状态位优化，100%，0ms
	//状态位是用来加速连续的pop和push的
private:
	stack<int> stk;
	stack<int> lin;
	bool pushing;

public:
	/** Initialize your data structure here. */
	MyQueue() {
		//初始是push状态
		pushing = true;
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		//当当前不是push状态时需要反转一次
		//用状态位防止多余的反转
		if (!pushing) {
			pushing = true;
			//将二号栈的内容全部转移到一号栈
			//这样使得内容方向反转
			while (!lin.empty()) {
				stk.push(lin.top());
				lin.pop();
			}
		}
		//压入
		stk.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//类似push
		if (pushing) {
			pushing = false;
			while (!stk.empty()) {
				lin.push(stk.top());
				stk.pop();
			}
		}
		int ret = lin.top();
		lin.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		//类似pop
		if (pushing) {
			pushing = false;
			while (!stk.empty()) {
				lin.push(stk.top());
				stk.pop();
			}
		}
		return lin.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		//利用状态位来读取对应栈的信息
		//虽然有两个栈但是它们只有一个会有内容
		if (pushing) {
			return stk.empty();
		}
		else {
			return lin.empty();
		}
	}
};