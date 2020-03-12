/*
堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。

当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，popAt 应返回 -1.

示例1:

 输入：
["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
[[1], [1], [2], [1], [], []]
 输出：
[null, null, null, 2, 1, -1]
示例2:

 输入：
["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
[[2], [1], [2], [3], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, 3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stack-of-plates-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    struct PlateStack {
        int* stack;
        PlateStack* next = NULL;
        PlateStack* prev = NULL;
        int cur = 0;
        PlateStack(int cap) {
            stack = new int[cap];
        }
    };

    PlateStack* use;
    PlateStack* now;
    PlateStack* del;
    int cap;

public:
    StackOfPlates(int cap) {
        this->cap = cap;
        use = new PlateStack(cap);
        now = use;
        del = new PlateStack(cap);
    }

    void push(int val) {
        if (now->cur == cap) {
            newNow();
        }
        now->stack[now->cur] = val;
        ++now->cur;
    }

    int pop() {
        if (now->cur == 0) {
            if (!delStk(now))
                return -1;
        }
        --now->cur;
        int ret = now->stack[now->cur];
        if (now->cur == 0) {
            delStk(now);
        }
        return ret;
    }

    int popAt(int index) {
        PlateStack* find = use;
        for (int i = 0; i < index; i++) {
            if (find == NULL) {
                return -1;
            }
            find = find->next;
        }

        if (find == NULL) {
            return -1;
        }

        if (find->cur == 0) {
            if (!delStk(find))
                return -1;
        }

        --find->cur;
        int ret = find->stack[find->cur];
        if (find->cur == 0) {
            delStk(find);
        }
        return ret;
    }

    void newNow() {
        if (del != NULL) {
            now->next = del;
            del->prev = now;
            del = del->next;
            now = now->next;
            now->next = NULL;
        }
        else {
            now->next = new PlateStack(cap);
            now->next->prev = now;
            now = now->next;
            now->next = NULL;
        }
    }

    bool delStk(PlateStack* tar) {
        if (!tar || tar->next == NULL && tar->prev == NULL) {
            return false;
        }

        if (tar->next) {
            if (tar->prev) {
                tar->prev->next = tar->next;
                tar->next->prev = tar->prev;
            }
            else {
                tar->next->prev = NULL;
            }
            if (now == tar) {
                now = tar->next;
                if (use == tar) {
                    use = tar->next;
                }
            }
        }
        else {
            tar->prev->next = NULL;
            if (now == tar) {
                now = tar->prev;
            }
        }

        if (del != NULL) {
            tar->next = del;
            del->prev = tar;
            del = del->prev;
            del->prev = NULL;
        }
        else {
            del = tar;
            del->prev = NULL;
            del->next = NULL;
        }

        return true;
    }
};