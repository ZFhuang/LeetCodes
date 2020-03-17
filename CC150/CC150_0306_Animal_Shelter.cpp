/*
有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。
在收养该收容所的动物时，
收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，
或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。
换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，
实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。
允许使用Java内置的LinkedList数据结构。

enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。
dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

示例1:
 输入：
["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [], [], []]
 输出：
[null,null,null,[0,0],[-1,-1],[1,0]]

示例2:
 输入：
["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
 输出：
[null,null,null,null,[2,1],[0,0],[1,0]]

说明:
收纳所的最大容量为20000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/animal-shelter-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    //记录了时间的队列，操作复杂因此很慢,28.9%,256ms
    //加速的关键在于询问考官从而知道编号是自增的，本来就无需记录时间
public:
    AnimalShelf() {
        time = 0;
    }

    //将编号和时间一起压入
    void enqueue(vector<int> animal) {
        if (animal[1] == 0) {
            Cat.push({ animal[0],time });
            ++time;
        }
        else {
            Dog.push({ animal[0],time });
            ++time;
        }
    }

    vector<int> dequeueAny() {
        //要注意队列是使用front得到队列头的
        if (Cat.empty() && Dog.empty()) {
            return { -1,-1 };
        }
        if (Cat.empty() && !Dog.empty()) {
            vector<int> ret = { Dog.front()[0],1 };
            Dog.pop();
            return ret;
        }
        if (Dog.empty() && !Cat.empty()) {
            vector<int> ret = { Cat.front()[0],0 };
            Cat.pop();
            return ret;
        }

        if (Cat.front()[1] < Dog.front()[1]) {
            vector<int> ret = { Cat.front()[0],0 };
            Cat.pop();
            return ret;
        }
        else {
            vector<int> ret = { Dog.front()[0],1 };
            Dog.pop();
            return ret;
        }
    }

    vector<int> dequeueDog() {
        if (Dog.empty()) {
            return { -1,-1 };
        }
        vector<int> ret = { Dog.front()[0],1 };
        Dog.pop();
        return ret;
    }

    vector<int> dequeueCat() {
        if (Cat.empty()) {
            return { -1,-1 };
        }
        vector<int> ret = { Cat.front()[0],0 };
        Cat.pop();
        return ret;
    }

private:
    queue<vector<int>> Dog;
    queue<vector<int>> Cat;
    int time;

    //由于编号自增，只保存了编号的版本,120ms
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        int type = animal[1];
        int num = animal[0];
        if (type == 1)dogs.push(num);
        else cats.push(num);
    }

    vector<int> dequeueAny() {
        //写得花哨其实判断量没有变少
        vector<int> res(2, -1);
        if (!dogs.empty()) {
            res[0] = dogs.front(), res[1] = 1;
        }
        if (!cats.empty() && (res[0] == -1 || cats.front() < res[0]))
            res[0] = cats.front(), res[1] = 0;
        if (res[1] == 0)cats.pop();
        else if (res[1] == 1) dogs.pop();
        return res;

    }

    vector<int> dequeueDog() {
        vector<int> res(2, -1);
        if (!dogs.empty())res[0] = dogs.front(), dogs.pop(), res[1] = 1;
        return res;
    }

    vector<int> dequeueCat() {
        vector<int> res(2, -1);
        if (!cats.empty())res[0] = cats.front(), cats.pop(), res[1] = 0;
        return res;
    }
private:
    queue<int> dogs;
    queue<int> cats;
};