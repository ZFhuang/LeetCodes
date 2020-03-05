/*
给定两个（单向）链表，判定它们是否相交并返回交点。
请注意相交的定义基于节点的引用，而不是基于节点的值。
换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），
则这两个链表相交。


示例 1：

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，
链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；
在 B 中，相交节点前有 3 个节点。

示例 2：

输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，
链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；
在 B 中，相交节点前有 1 个节点。

示例 3：

输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。

注意：

如果两个链表没有交点，返回 null 。
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //暴力法,5.1%,680ms
    //最容易想到的方法，直接两重循环查找，非常慢，O(n2)时间复杂度
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p = headA, * q = headB;
        while (p) {
            q = headB;
            while (q) {
                if (p == q) {
                    return p;
                }
                q = q->next;
            }
            p = p->next;
        }
        return NULL;
    }

    //长度法,54.1%,60ms
    //两节点相同意味着那个节点之后的节点都相同，即相同节点之后的长度都相同
    //那么遍历得到长度后将两链表调整到同个长度后同时遍历即可找到,O(n)复杂度
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)
            return NULL;
        ListNode* p = headA, * q = headB;
        //查找两链表长度
        int lenA = 0, lenB = 0;
        while (p->next) {
            p = p->next;
            ++lenA;
        }
        while (q->next) {
            q = q->next;
            ++lenB;
        }
        //若最后一个元素不同则必然不相交
        if (p != q) {
            return NULL;
        }
        //回指
        p = headA;
        q = headB;
        //利用长度差异调整一次
        if (lenA > lenB) {
            while (lenA > lenB) {
                p = p->next;
                --lenA;
            }
        }
        else if (lenB > lenA) {
            while (lenB > lenA) {
                q = q->next;
                --lenB;
            }
        }
        //同时遍历查找相同节点
        while (p && q) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return NULL;
    }

    //双指针法,100%,40ms
    //让两指针互相追赶，利用两链表的长度差距改变指针的位置，省去匹配链表长度的一步
    //可以画图辅助理解，假设有下图，下链表比较短且在4处于上链表交叉
    //1-2-3-4-5
    //  6-7-|
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)return NULL;
        ListNode* curA = headA, * curB = headB;
        //当两个指针相同时跳出
        while (curA != curB) {
            //如例：两链表同时前进时，下链表会先到中点
            if (curA == NULL && curB == NULL)break;
            else {
                //若某指针先到终点，则切换到另一串，省下的时间会在长串中被补偿
                //这样先到终点的指针和后到终点的指针会被调整为在同一速度上
                //也就是完成了上一种做法中的长度匹配步骤
                //同时到达终点还未交叉表示无交叉
                if (curA == NULL)curA = headB;
                else  curA = curA->next;
                if (curB == NULL)curB = headA;
                else curB = curB->next;
            }
        }
        //按照情况不同来返回
        if (curA == curB)return curA;
        else return NULL;
    }
};