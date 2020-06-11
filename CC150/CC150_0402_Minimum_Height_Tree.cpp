/*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

		  0
		 / \
	   -3   9
	   /   /
	 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 利用输入的数组有序的特性，利用子结构不断将中点加入树作为分支结点直到建树完成
	// 基础的中点划分方法,24ms,80.35%
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) {
			return nullptr;
		}
		if (nums.size() == 1) {
			return new TreeNode(nums[0]);
		}
		int mid = nums.size() / 2;
		TreeNode* t = nullptr;
		t = subStruct(t, nums, 0, mid, nums.size());
		return t;
	}

	TreeNode* subStruct(TreeNode* t, vector<int>& nums, int left, int mid, int right) {
		t = new TreeNode(nums[mid]);
		if (left < mid) {
			int m = (mid - left) / 2 + left;
			t->left = subStruct(t->left, nums, left, m, mid);
		}
		if (right > mid + 1) {
			int m = (right - mid + 1) / 2 + mid;
			t->right = subStruct(t->right, nums, mid + 1, m, right);
		}
		return t;
	}

	// 同样是分治法，但结构更紧凑,16ms,94.1%
	TreeNode* dfs(const vector<int>& nums, int L, int R)
	{
		// 退出条件
		if (L > R)
			return nullptr;

		// 找到中点
		int mid = (L + R) / 2;
		// 初始化当前的中间结点
		TreeNode* ptr = new TreeNode(nums[mid]);
		// 左右两个中点正好有一位的差别，分成两块，然后调用
		ptr->left = dfs(nums, L, mid - 1);
		ptr->right = dfs(nums, mid + 1, R);
		return ptr;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return dfs(nums, 0, nums.size() - 1);
	}
};