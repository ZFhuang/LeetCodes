/*
实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
	2
   / \
  1   3
输出: true

示例 2:
输入:
	5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
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
	// 传统写法，用中序遍历得到排序好的数组，16ms，88.01%
	// 中序遍历正确的查找树会得到从小到大的排序
	void inOrder(TreeNode* root, vector<int>& inorder) {
		if (root == nullptr) return;
		inOrder(root->left, inorder);
		inorder.push_back(root->val);
		inOrder(root->right, inorder);
	}

	bool isValidBST(TreeNode* root) {
		// 空结点情况
		if (root == nullptr) return true;
		vector<int> inorder;
		// 初始化中序遍历数组
		inOrder(root, inorder);
		// 遍历得到的数组查找是否有不符合情况的元素
		for (int i = 1; i < inorder.size(); ++i) {
			if (inorder[i] <= inorder[i - 1]) {
				return false;
			}
		}
		return true;
	}

public:
	// 高度精简的写法，12ms，96.5%
	// 关键是利用递归树时左子树必比子树根结点小，右子树比根大的特性
	// 在递归途中直接带入最小最大值
	bool isValidBST(TreeNode* root) {
		// 对于根结点任意情况都成立
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode* root, long min, long max) {
		// 处理空指针
		return root == nullptr ||
			// 与链中的最值比较，左半部分比小于最大，右半比大于最小
			(root->val > min && root->val < max &&
				// 左深入，本结点作为子树的最大值输入
				isValidBST(root->left, min, root->val) &&
				// 右深入，本结点作为子树的最小值输入
				isValidBST(root->right, root->val, max));
	}
};