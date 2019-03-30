//大数字相加

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
