/*
栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

示例1:

 输入：
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
 输出：
[null,null,null,1,null,2]
示例2:

 输入：
["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
[[], [], [], [1], [], []]
 输出：
[null,null,null,null,null,true]
说明:

栈中的元素数目在[0, 5000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-of-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    //传统的缓冲栈写法,48.5%,144ms
    //本质上是进行了动态的插入排序，很慢
private:
    stack<int> stk;
    stack<int> tmp;

public:
    SortedStack() {

    }

    void push(int val) {
        if (stk.empty()) {
            stk.push(val);
        }
        else {
            if (stk.top() >= val) {
                stk.push(val);
            }
            else {
                //找到正好可以放入新元素的位置
                //遍历过的元素放入缓冲区
                while (!stk.empty()) {
                    tmp.push(stk.top());
                    stk.pop();
                    if (!stk.empty() && stk.top() >= val) {
                        break;
                    }
                }
                //压入
                stk.push(val);
                //从缓冲区中把暂存的元素放回
                while (!tmp.empty()) {
                    stk.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }

    //余下操作正常
    void pop() {
        if (stk.empty()) {
            return;
        }
        stk.pop();
    }

    int peek() {
        if (stk.empty()) {
            return -1;
        }
        return stk.top();
    }

    bool isEmpty() {
        return stk.empty();
    }

    //优化的写法,91.4%,20ms
    //主要是利用滑动两个栈来减少出入栈的次数
public:
    SortedStack() {
    }

    //在两个栈中互相抛接，相当于把目标排列滑动到符合val的中间值
    //s2是小于val的栈，s1是大于val的栈
    void push(int val) {
        //将s2中所有大于val都压入s1
        while (!s2.empty() && s2.top() > val) {
            //emplace，C11新特性
            //类似于push，但是emplace可以直接自动构造对象，功能比push多
            //push只能在构造完对象后复制进去
            //所以对于需要构造对象的场合用emplace更省内存
            //见：https://blog.csdn.net/Kprogram/article/details/82055673
            s1.emplace(s2.top());
            s2.pop();
        }
        //将s1中所有小于val的都压入s2
        while (!s1.empty() && s1.top() < val) {
            s2.emplace(s1.top());
            s1.pop();
        }
        //剩下的位置是等于val的，压入s1
        //初始也是压入s1
        s1.emplace(val);
    }

    void pop() {
        //将s2(小于val)的元素全部压到s1中
        while (!s2.empty()) {
            s1.emplace(s2.top());
            s2.pop();
        }
        if (!s1.empty()) s1.pop();
    }

    //同pop
    int peek() {
        while (!s2.empty()) {
            s1.emplace(s2.top());
            s2.pop();
        }
        return s1.empty() ? -1 : s1.top();
    }

    //两个栈都空时才空，因为完整的数据是由两个栈一起保存的
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
private:
    //双栈
    stack<int> s1, s2;
};