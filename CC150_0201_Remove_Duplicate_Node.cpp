/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //有使用缓冲区的单指针做法，96.29%，24ms
    //每次发下有一个重复就会更改一下当前链表，所以比较慢
    ListNode* removeDuplicateNodes(ListNode* head) {
        //空链表或单元素链表是不会重复的
        if (!head || !head->next)
            return head;

        //缓冲区
        bool dup[20001];
        memset(dup, 0, sizeof(bool) * 20001);
        ListNode* p = head;
        //先存入第一个元素
        dup[p->val] = true;
        //从第二个元素开始判断
        while (p->next) {
            //下一个元素无重复时
            if (!dup[p->next->val]) {
                //标记并进到下一个
                dup[p->next->val] = true;
                p = p->next;
            }
            //出现重复时
            else {
                //跳过这个元素
                p->next = p->next->next;
            }
        }

        return head;
    }

    //有使用缓冲区的双指针做法，99.5%，20ms
    //思路与解法一一样
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next)
            return head;

        bool visited[20001] = { false };

        ListNode* dummyHead = new ListNode(-65535);
        dummyHead->next = head;

        //一个滞后的指针来指向上一个元素
        ListNode* pre = dummyHead, * cur = head;

        while (cur) {
            if (visited[cur->val] == false) {
                visited[cur->val] = true;
                pre = cur;
                cur = cur->next;
            }
            else {
                pre->next = cur->next;
                cur = pre->next;
            }
        }

        return head;
    }

    //不使用缓冲区的做法，14.6%，484ms
    //此方法需要O(n2)的复杂度，用两个指针来暴力判断是否出现，很慢
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next)
            return head;

        //p指针是当前位置，s指针是用于在前面搜索是否有重复
        ListNode* p = head, * s = head;
        while (p->next) {
            s = head;
            bool dup = false;
            //从头到当前节点开始搜索是否有重复
            while (s != p->next) {
                if (s->val == p->next->val) {
                    dup = true;
                    break;
                }
                else {
                    s = s->next;
                }
            }
            //对重复进行处理
            if (dup) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }

        return head;
    }
};