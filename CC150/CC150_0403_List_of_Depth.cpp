/*
给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

示例：

输入：[1,2,3,4,5,null,7,8]

		1
	   /  \
	  2    3
	 / \    \
	4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/list-of-depth-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// 用广度优先搜索BFS,用到一个队列储存当前的层数
	// 0ms,100%
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		vector<ListNode*> result;
		// 排除空指针情况
		if (tree == nullptr) {
			return result;
		}
		// BFS队列
		queue<TreeNode*> qt;
		// 记录当前结点层数的队列，与qt同步
		queue<int> qi;
		// 压入第一个结点
		qt.push(tree);
		qi.push(1);
		// 手动管理返回值中的子链表
		ListNode* head = nullptr;
		ListNode* rear = nullptr;
		// 暂存当前的树结点
		TreeNode* tmp = nullptr;
		// 当前结点的层数
		int now = 0;
		// 队列为空代表完全遍历完树了
		while (!qt.empty())
		{
			// BFS基本操作，先弹出队头结点
			tmp = qt.front();
			now = qi.front();
			// 分两个情况决定将结点的值记录到哪里
			if (head == nullptr) {
				head = new ListNode(tmp->val);
				rear = head;
			}
			else {
				rear->next = new ListNode(tmp->val);
				rear = rear->next;
			}
			// 弹出这个结点
			qt.pop();
			qi.pop();
			// 然后压入左右子结点，同时将当前层数加一压入
			if (tmp->left != nullptr) {
				qt.push(tmp->left);
				qi.push(now + 1);
			}
			if (tmp->right != nullptr) {
				qt.push(tmp->right);
				qi.push(now + 1);
			}
			// 当下一结点的层数与当前结点不同时，代表到达本层的尾部，需要压入结果
			// 由于空队列返回值为-1，因此无需额外判断
			if (qi.front() != now) {
				result.push_back(head);
				// 重置链表头指针
				head = nullptr;
			}
		}
		// 返回最终结果
		return result;
	}

	// 无需层数队列，更简洁的写法
	// 在知道本层的元素数量后，只要边遍历边把本层元素的子元素都压入
	// 在遍历完本层数量的元素后剩下的就都是下一层的元素了，然后又开始一个循环
	// 0ms,100%
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		// 返回的结果
		vector<ListNode*> ans;
		// 处理空树的情况
		if (tree == NULL) return ans;
		// 同样先压入头结点到队列
		queue<TreeNode*> q;
		q.push(tree);
		while (!q.empty()) {
			// 子链表头
			ListNode* t = new ListNode;
			// 子链表尾
			ListNode* p = t;
			// 计算目前队列中的元素数量，在下面的循环前这部分元素全都是同一层的
			// 遍历完这部分元素就代表处理好本层的数据了，新压入的元素都在这个数量范围之外
			int size = q.size();
			for (int k = 0; k < size; k++) {
				TreeNode* tmp = q.front();
				q.pop();
				// 存入当前的结点
				t->next = new ListNode(tmp->val);
				// 移动链表
				t = t->next;
				// 压入左右结点
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			// 向结果压入子链表
			ans.push_back(p->next);
		}
		return ans;
	}
};