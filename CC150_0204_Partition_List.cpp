/*
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //理解题意是关键,70.2%,8ms
    //题目说的很乱，其实就是要把链表大于的和小于的元素分立两边
    //然后不限制大于和小于部分的内部顺序，答案是不唯一的
    ListNode* partition(ListNode* head, int x) {
        //思路自然就是两个额外的链表
        ListNode* Less = new ListNode(0);
        ListNode* Larger = new ListNode(0);
        ListNode* p = head, * less = Less, * larger = Larger;
        while (p) {
            //小于的放一边
            if (p->val < x) {
                less->next = p;
                p = p->next;
                less = less->next;
                less->next = NULL;
            }
            //大于的放另一边
            else {
                larger->next = p;
                p = p->next;
                larger = larger->next;
                larger->next = NULL;
            }
        }
        //最后将两个链表连接起来
        less->next = Larger->next;
        return Less->next;
    }
};