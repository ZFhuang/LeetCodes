/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

class Solution {
public:
	//普通的链表计算，8.9%
	//最容易想到的解法，但写得太过繁琐了
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//进位符和暂存符
		int add = 0, temp = 0;
		//结果链表
		ListNode* ret = new ListNode(0);
		ListNode* p = ret;
		while (true) {
			add = 0, temp = p->val;
			//判断相加链表的三种情况
			if (l1 == NULL) {
				temp += l2->val;
				l2 = l2->next;
			}
			else if (l2 == NULL) {
				temp += l1->val;
				l1 = l1->next;
			}
			else {
				temp += l1->val + l2->val + add;
				l1 = l1->next;
				l2 = l2->next;
			}
			//进位操作
			if (temp >= 10) {
				add = 1;
				temp -= 10;
			}
			p->val = temp;
			if (l1 == NULL && l2 == NULL) {
				if (add != 0) {
					//末尾需要判断
					p->next = new ListNode(add);
				}
				break;
			}
			//链表继续
			p->next = new ListNode(add);
			p = p->next;
		}
		return ret;
	}

	//优化的链表计算，99.24%
	//主要是通过更加极致的编写手法来优化代码的执行，减少了很多判断
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		auto p1 = l1, p2 = l2, q = &dummy;
		int carry = 0;
		//当链表中有任何一个未完或还有进位时
		while (p1 || p2 || carry) {
			//使用三目运算符简化代码，这个写法非常漂亮
			//取出链表当前对应元素的值(无则取0)相加再与进位相加
			auto temp = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
			//得到的值除10得到其十位部分成为新的进位
			carry = temp / 10;
			//结果链表的新节点的值则是和值的个位部分
			q->next = new ListNode(temp % 10);
			//三个链表前进，其中用if轻松解决空链表前进的问题
			q = q->next;
			if (p1)p1 = p1->next;
			if (p2)p2 = p2->next;
		}
		//最后返回结果链表
		return dummy.next;
	}
};
