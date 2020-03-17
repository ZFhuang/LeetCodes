/*
描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

示例1:

 输入：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 输出：
[null, null, null, 1, -1, -1, true]
说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
示例2:

 输入：
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, -1, -1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-in-one-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //传统一维数组,74.2%,84ms
    //一维数组实现，采用按照3来划分三个栈，长度是静态的
    //这道题耗时差别很大
    //数组也可以用向量vector来替代，效率接近
    //可以借助循环数组的想法做成大小动态适应的栈，但是代码会复杂很多而且效率也会降低
    int* stack;
    int p[3];
    int stackSize;

    TripleInOne(int stackSize) {
        stack = new int[stackSize * 3];
        this->stackSize = stackSize;
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
    }

    void push(int stackNum, int value) {
        //栈满时跳出
        if ((p[stackNum] - stackNum + 3) / 3 > stackSize) {
            return;
        }
        stack[p[stackNum]] = value;
        //入栈加数量
        p[stackNum] += 3;
    }

    int pop(int stackNum) {
        //栈空
        if (p[stackNum] - 3 < 0) {
            return -1;
        }
        int ret = stack[p[stackNum] - 3];
        //出栈退数量
        p[stackNum] -= 3;
        return ret;
    }

    int peek(int stackNum) {
        //栈空
        if (p[stackNum] - 3 < 0) {
            return -1;
        }
        return stack[p[stackNum] - 3];
    }

    bool isEmpty(int stackNum) {
        //栈空
        if (p[stackNum] - 3 < 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
};