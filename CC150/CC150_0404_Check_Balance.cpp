/*
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


示例 1:
给定二叉树 [3,9,20,null,null,15,7]
	3
   / \
  9  20
	/  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
	  1
	 / \
	2   2
   / \
  3   3
 / \
4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-balance-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 普通迭代法，包含剪枝,16ms,92.14%
	bool isBalanced_1(TreeNode* root) {
		// 特殊情况
		if (root == nullptr)
			return true;

		// 判断左右子树，递归返回子树高度
		int l = height(root->left);
		if (l == -1)
			return false;

		int r = height(root->right);
		if (r == -1)
			return false;

		// 比较高度，-1代表子树已经不平衡被剪枝
		if (l >= r) {
			if (l - r > 1)
				return false;
			else {
				if (r - l > 1)
					return false;
				return true;
			}
		}
	}
	int height(TreeNode* p) {
		if (p == nullptr)
			return 0;
		int l = height(p->left);
		if (l == -1)
			return -1;
		int r = height(p->right);
		if (r == -1)
			return -1;
		// 用-1来在返回时标记
		if (l >= r) {
			if (l - r > 1)
				return -1;
			return l + 1;
		}
		else {
			if (r - l > 1)
				return -1;
			return r + 1;
		}
	}

	// 利用全局变量的剪枝法，更简洁,16ms,92.14%
	// 全局变量直接标记
	bool balance = true;
	int helper(TreeNode* root) {
		// 剪枝情况和特殊情况
		if (!balance || root == nullptr)
			return 0;
		// 左右递归
		int left = helper(root->left), right = helper(root->right);
		// 判断两子树深度
		if (abs(left - right) > 1)
			balance = false;
		// 返回最深的+1
		return max(left, right) + 1;
	}
	bool isBalanced_2(TreeNode* root) {
		helper(root);
		return balance;
	}
};