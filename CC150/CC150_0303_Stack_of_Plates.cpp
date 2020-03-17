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
    //不使用STL，设置空闲链表，93.0%,60ms
    //每个栈都是双向链表方便操作
    //删除空栈时改为将空栈存入空闲链表中
    //申请栈时先尝试从空闲链表分配，加速内存分配
    //可以再给空闲链表增加阈值减少无用内存的占用
private:
    struct PlateStack {
        int* stack;
        //双向链表方便操作
        PlateStack* next = NULL;
        PlateStack* prev = NULL;
        int cur = 0;
        PlateStack(int cap) {
            stack = new int[cap];
        }
    };

    //在用栈表头
    PlateStack* use;
    //栈表尾
    PlateStack* now;
    //空闲栈表
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
        //特殊情况跳出
        if (cap == 0) {
            return;
        }
        //当指针达到栈尾时申请新栈
        if (now->cur == cap) {
            newNow();
        }
        //存入
        now->stack[now->cur] = val;
        ++now->cur;
    }

    int pop() {
        //当试图出栈一个空栈时
        if (now->cur == 0) {
            //删除并检测是否已经没有元素了
            if (!delStk(now))
                return -1;
        }
        //出栈
        --now->cur;
        int ret = now->stack[now->cur];
        //出栈后若栈空则删除栈
        if (now->cur == 0) {
            delStk(now);
        }
        return ret;
    }

    int popAt(int index) {
        //从头遍历所需序号的栈
        //这部分可以利用双向链表的特性，储存左右两边的栈数量进行加速搜索
        PlateStack* find = use;
        for (int i = 0; i < index; i++) {
            if (find == NULL) {
                return -1;
            }
            find = find->next;
        }

        //找不到栈时报错
        if (find == NULL) {
            return -1;
        }

        //以下类似pop
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

    //新建栈
    void newNow() {
        //当空闲链表非空时
        if (del != NULL) {
            //将空闲链表头取一个作为新栈
            now->next = del;
            del->prev = now;
            del = del->next;
            now = now->next;
            now->next = NULL;
        }
        else {
            //否则新建
            now->next = new PlateStack(cap);
            now->next->prev = now;
            now = now->next;
            now->next = NULL;
        }
    }

    bool delStk(PlateStack* tar) {
        //当目标栈是唯一栈时，表示全空
        if (!tar || tar->next == NULL && tar->prev == NULL) {
            return false;
        }

        //存在下一个栈时
        if (tar->next) {
            //存在上一个栈时
            if (tar->prev) {
                //通过指针重指跳过当前栈
                tar->prev->next = tar->next;
                tar->next->prev = tar->prev;
            }
            else {
                //只有下一个栈时，此时必然是use栈，也即是栈表头
                //更改链表的同时需要改变use的位置
                tar->next->prev = NULL;
                use = tar->next;
            }
        }
        else {
            //没有下一个栈时，此时必然是now栈，也即是栈表尾
            //更改链表的同时需要改变now的位置
            tar->prev->next = NULL;
            now = tar->prev;
        }

        //重整完链表后，类似new操作将腾出来的栈放到空闲链表头
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

    //样例的使用STL的方法，94.6%,56ms
    //使用已经写好的容器能简化代码
public:
    StackOfPlates(int cap) {
        len = cap;
    }

    void push(int val) {
        if (len == 0) {
            return;
        }
        //栈表空或当前到达栈尾时
        if (rec.size() == 0 || rec[rec.size() - 1].size() == len) {
            //新建栈并压入数据再压入链表
            stack<int> s;
            s.push(val);
            rec.push_back(s);
        }
        else {
            //直接压入
            rec[rec.size() - 1].push(val);
        }
    }

    int pop() {
        //栈表非空时
        if (rec.size() != 0) {
            int r = rec[rec.size() - 1].top();
            rec[rec.size() - 1].pop();
            //若当前栈空，则弹出栈
            if (rec[rec.size() - 1].empty()) {
                rec.pop_back();
            }
            return r;
        }
        return -1;
    }

    int popAt(int index) {
        //检测是否序号在链表中
        if (index < rec.size()) {
            //直接用下标访问
            int r = rec[index].top();
            rec[index].pop();
            if (rec[index].empty()) {
                rec.erase(rec.begin() + index);
            }
            return r;
        }
        return -1;
    }
private:
    //栈向量嵌套容器
    vector<stack<int>> rec;
    int len = 0;
};