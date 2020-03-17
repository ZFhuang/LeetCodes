/*
给定两个用链表表示的整数，每个节点包含一个数位。
这些数位是反向存放的，也就是个位排在链表首部。
编写函数对这两个整数求和，并用链表形式返回结果。

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：假设这些数位是正向存放的，请再做一遍。

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-lists-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//链表直接相加,95.04%,16ms
	//由于数据选得不好，这道题LeetCode判题机运行时间波动极大
	//思路是同时遍历两个链表，相加放到第三个链表中，要考虑进位
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* P = new ListNode(0);
		ListNode* p = P;
		while (l1 || l2) {
			//相加，为了让两个链表能完整写在一个循环中，选择这样的多个if结构
			int add = 0;
			if (l1 && l2)
				add = l1->val + l2->val;
			else if (l1)
				add = l1->val;
			else if (l2)
				add = l2->val;
			//放到第三个链表中
			p->next = new ListNode(add % 10);
			//链表一同前进
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
			p = p->next;
			//进位判断
			if (add / 10 > 0) {
				if (l1 && l2) {
					l1->val = l1->val + 1;
				}
				else if (l1) {
					l1->val = l1->val + 1;
				}
				else if (l2) {
					l2->val = l2->val + 1;
				}
				else {
					//都清零时退出
					p->next = new ListNode(1);
					break;
				}
			}
		}

		return P->next;
	}
};