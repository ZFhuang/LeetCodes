/*
给定一个有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。


示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //快慢指针找环入口,98.2%,8ms
    //也称Floyd判圈算法/龟兔赛跑算法
    //还有复杂度常数比较低的Brents算法，但不适用于这道题
    //详见：https://blog.csdn.net/u011221820/article/details/78821464
    //当链表中有环时，不同前进速度(设为2)的指针必然会在某处相遇（龟兔环形赛跑）
    //当相遇时，如果让慢指针再走一圈，快指针不动，再相遇时得到环的长度
    //而若相遇时让快指针返回起点再以慢指针的速度同时前进，则两指针会在环的入口处相遇
    //因为慢针走到旧相遇点时：
    //快针的行走距离是x1+x2+x3+x2，慢针的行走距离是x1+x2(x1是环外的距离)
    //由于2(x1+x2)=x1+x2+x3+x2，所以得x3=x1
    //因此当快针回到起点，以慢针的速度前进时，当走了x1的距离时，慢针也恰好走了x3的距离
    //也即是在环入口相遇
    ListNode* detectCycle(ListNode* head) {
        //先排除基础情况
        if (!head || !head->next) {
            return NULL;
        }
        if (head->next == head) {
            return head;
        }
        ListNode* fast = head, * slow = head;

        //类似0207的循环条件，这样保证了快指针慢指针都不会错误访问
        while (fast && fast->next) {
            //快指针的速度是慢指针的两倍
            fast = fast->next->next;
            slow = slow->next;
            //当两指针重叠时
            if (fast == slow) {
                //将快指针回到开头
                fast = head;
                while (slow != fast) {
                    //相同速度前进
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};