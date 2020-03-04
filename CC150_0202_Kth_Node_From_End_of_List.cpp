/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //双指针思路,77.4%,4ms
    int kthToLast(ListNode* head, int k) {
        //一个表示倒数k位的元素，一个是当前元素
        ListNode* p_k = NULL, * cur = head;
        int count = 1;
        //当当前元素到尾部跳出
        while (cur != NULL) {
            //达到倒数区时赋值
            if (count == k) {
                p_k = head;
            }
            //一同前进
            if (count > k) {
                p_k = p_k->next;
            }
            cur = cur->next;
            ++count;
        }
        return p_k->val;
    }
};