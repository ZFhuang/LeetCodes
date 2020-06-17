/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:
输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2

示例 2:
输入: root = [5,3,6,2,4,null,null,1], p = 6

	  5
	 / \
	3   6
   / \
  2   4
 /
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<vector>
using namespace std;

class Solution {
public:
	// 类似上一题的思路，40ms，84.28%
	// 先中序遍历得到数组，然后遍历数组得到后继结点
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == nullptr || p == nullptr) {
			return nullptr;
		}
		vector<TreeNode*> in;
		// 中序
		inorder(root, p->val, in);
		// 遍历
		for (int i = 0; i < in.size() - 1; ++i) {
			if (in[i]->val == p->val) {
				return in[i + 1];
			}
		}
		return nullptr;
	}

	void inorder(TreeNode* root, int pval, vector<TreeNode*>& in) {
		if (root == nullptr) {
			return nullptr;
		}
		// 中序，也就是左中右
		inorder(root->left, pval, in);
		in.push_back(root);
		inorder(root->right, pval, in);
	}

	// 有剪枝的中序遍历，40ms，84.28%
	// 当找到目标结点后直接返回下一个结点
	TreeNode* result=nullptr;
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == nullptr || p == nullptr) {
			return nullptr;
		}
		vector<TreeNode*> in;
		// 中序
		inorder(root, p->val, in);
		return result;
	}

	 void inorder(TreeNode* root, int pval, vector<TreeNode*>& in) {
		if (root == nullptr|| result!=nullptr) {
			return;
		}
		// 中序，也就是左中右
		inorder(root->left, pval, in);
		// 找到目标时返回
		if (result == nullptr && !in.empty() && in.back()->val == pval) {
			// 记录结果
			result = root;
			return;
		}
		in.push_back(root);
		inorder(root->right, pval, in);
	}

	// 利用二叉搜索树的特性，32ms，93.4%
	// 因为是中序后继，因此后继必然是子树的中间结点或右侧结点
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		// 特殊情况
		if (root == nullptr || p == nullptr) return nullptr;
		// 判断目标结点可能存在于哪个子树
		// 实际上是进行了二叉树搜索的过程，最终可以得到目标所在的最小子树的分支
		// 最终返回会发生在叶子结点中
		if (p->val >= root->val) {
			// 没有找到目标前是正常二叉搜索
			// 找到目标时，目标必然在子树根结点，此时中序的后续时子树的右子树的最左结点
			// 正因为接下来往右子树查找元素必然都大于目标
			// 因此搜索自然就会不断往左也就是进入下面的分支
			return inorderSuccessor(root->right, p);
		}
		else {
			// 没有找到目标前是正常二叉搜索
			// 找到目标后这是查找最左结点的部分，由于此时这里是右子树
			// 因此结点都大于目标，因此不断往左直到叶子结点，返回叶子自身
			TreeNode* left = inorderSuccessor(root->left, p);
			return left ? left : root;
		}
	}
};