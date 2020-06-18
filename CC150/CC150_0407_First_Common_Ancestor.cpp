/*
设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。

例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]

	3
   / \
  5   1
 / \ / \
6  2 0  8
  / \
 7   4

示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-common-ancestor-lcci
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
	// 递归法，算法简洁，20ms，91.18%
    // https://leetcode-cn.com/problems/first-common-ancestor-lcci/solution/di-gui-jie-fa-python-3-c-by-z1m/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 找到某个目标结点时返回
        // 当下面没有找到时会返回nullpttr
		if (root == p || root == q || root == nullptr)
			return root;
        // 递归查找左右子树
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 当返回的左右指针都有值时，证明目标结点分别在此结点左右子树中且这就是交叉点
        // 此情况公共祖先必是当前的这个结点
		if (left && right)
			return root;
        // 返回左右指针中有值的那一个，当都为nullptr时返回nullptr
		return left ? left : right;
	}

    // 需要额外空间的方法，20ms，91.18%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        // 获得从根节点到 p 节点的路径
        vector<TreeNode*> ppath;
        getPath(root, p, ppath);

        // 获得从根节点到 q 节点到路径
        vector<TreeNode*> qpath;
        getPath(root, q, qpath);

        int m = min(ppath.size(), qpath.size());
        // 考虑 p 或 q 不存在的情况
        if (m == 0) return NULL; 
        // 找到最后一个公共节点，具体是返回两个路径发生分叉的位置，分叉处就是公共祖先
        for (int i = 1; i < m; i++) {
            if (ppath[i] != qpath[i]) return ppath[i - 1];
        }
        // 考虑 p 或 q 不存在的情况
        return ppath[m - 1] == qpath[m - 1] ? ppath[m - 1] : NULL;
    }

    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        // 空指针返回找不到路径
        if (!root) return false;
        // 将当前结点压入路径向量
        path.push_back(root);
        // 找到节点，直接返回
        if (root == target) return true; 
        // 左右递归查找，当找到有true时代表存在路径，直接返回
        if (getPath(root->left, target, path)) return true;
        if (getPath(root->right, target, path)) return true;
        // 当一直false时代表不是这个路径，弹出当前结点返回到上一层
        path.pop_back(); // 如果左右子树都没找到，清理路径
        return false;
    }
};