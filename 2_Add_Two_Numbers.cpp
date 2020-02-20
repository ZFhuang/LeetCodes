/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //普通的链表计算，64.9%
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //进位符和暂存符
        int add=0,temp=0;
        //结果链表
        ListNode* ret=new ListNode(0);
        ListNode* p=ret;
        while(true){
            add=0,temp=p->val;
            //判断相加链表的三种情况
            if(l1==NULL){
                temp+=l2->val;
                l2=l2->next;
            }
            else if(l2==NULL){
                temp+=l1->val;
                l1=l1->next;
            }else{
                temp+=l1->val+l2->val+add;
                l1=l1->next;
                l2=l2->next;
            }
            //进位操作
            if(temp>=10){
                add=1;
                temp-=10;
            }
            p->val=temp;
            if(l1==NULL&&l2==NULL){
                if(add!=0){
                    //末尾需要判断
                    p->next=new ListNode(add);
                }
                break;
            }
            //链表继续
            p->next=new ListNode(add);
            p=p->next;
        }
        return ret;
    }
};
