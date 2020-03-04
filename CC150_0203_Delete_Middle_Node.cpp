/*
实现一种算法，删除单向链表中间的某个节点（除了第一个和最后一个节点，不一定是中间节点），假定你只能访问该节点。

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-middle-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //删除节点,91.4%,8ms
    //题意是要删去参数输入的这个节点，没有给出前置节点
    void deleteNode(ListNode* node) {
        //由于没有给出前置，选择替换删去下一个节点
        //先把下一个节点的值赋值到当前节点
        node->val = node->next->val;
        //然后跳过下个节点
        node->next = node->next->next;
    }
};