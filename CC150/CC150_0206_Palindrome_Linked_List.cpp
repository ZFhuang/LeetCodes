/*
编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false
示例 2：

输入： 1->2->2->1
输出： true
 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //逆置链表法，67.6%,24ms
    //利用了回文串的一半逆序后与另一半会相同的特点
    bool isPalindrome(ListNode* head) {
        //先计算出链表的长度
        int len = 0;
        ListNode* p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        //长度小于等于1的必然是回文
        if (len <= 1) {
            return true;
        }
        //获取第一个元素和第二个元素
        ListNode* q = head, * r = NULL;
        p = head->next;
        q->next = NULL;
        //长度等于2的直接判断两个元素是否相等即可
        if (len == 2) {
            if (p->val == q->val) {
                return true;
            }
            else {
                return false;
            }
        }
        //计算中点的序号和寄偶
        int count = 1, half = len / 2;
        bool odd = len % 2;
        //将中点前的链表逆序
        while (p) {
            if (count >= half) {
                break;
            }
            r = p->next;
            p->next = q;
            q = p;
            p = r;
            ++count;
        }
        //若长度为奇则跳过中间元素
        if (odd) {
            p = p->next;
        }
        //继续遍历，若有不相同的元素即不是回文
        while (p && q) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }

    //快慢指针法,99.1%,16ms
    //优化的关键在于利用快慢指针来在一次遍历中找到中点并将前半段链表逆序
    bool isPalindrome(ListNode* head) {
        //空则返回
        if (!head) return true;
        //建立快慢指针，rh指向的是逆序的前半段链表开头
        ListNode* fast = head, * slow = head, * rh = new ListNode(0);
        //当快针存在且拥有下一针时循环
        //这个约束使得跳出时时快针是最后一个或空，慢针则是中间元素或中间两个的后一个
        while (fast && fast->next) {
            //快针走两步
            fast = fast->next->next;
            //慢针走一步且逆序
            slow = slow->next;
            head->next = rh->next;
            rh->next = head;
            head = slow;
        }
        //如果此时快针存在，代表慢针处于中间元素，慢再走一步
        if (fast) slow = slow->next;
        rh = rh->next;
        //从逆序链表开始遍历，和慢针一起遍历，因为此时慢针即是中位元素
        while (rh) {
            //判断返回
            if (rh->val != slow->val) return false;
            rh = rh->next;
            slow = slow->next;
        }

        return true;
    }
};