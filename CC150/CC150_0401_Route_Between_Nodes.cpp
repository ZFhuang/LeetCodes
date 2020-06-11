/*
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:

 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:

 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
提示：

节点数量n在[0, 1e5]范围内。
节点编号大于等于 0 小于 n。
图中可能存在自环和平行边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/route-between-nodes-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<vector>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
	//// 用DFS寻找通路
	//// 邻接矩阵法，耗内存和耗时都很大，会超时
	//bool mfindWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
	//	// 初始化邻接矩阵
	//	int** g = new int* [n];
	//	for (int i = 0; i < n; ++i) {
	//		g[i] = new int[n] {};
	//	}

	//	// 填入邻接矩阵
	//	for (auto iter = graph.begin(); iter != graph.end(); ++iter) {
	//		g[(*iter)[0]][(*iter)[1]] = 1;
	//	}

	//	return mdfs(n, g, start, target);
	//}

	//// 深度优先搜索
	//bool mdfs(int n, int** g, int start, int target) {
	//	for (int i = 0; i < n; ++i) {
	//		if (g[start][i] == 1) {
	//			if (i == target) {
	//				return true;
	//			}
	//			else {
	//				if (mdfs(n, g, i, target)) {
	//					return true;
	//				}
	//			}
	//			// 标记访问后的点
	//			g[start][i] = 2;
	//		}
	//	}
	//	return false;
	//}

	//// 邻接表处理,47.22%,540ms
	//// 此题如果用邻接矩阵会超时用，普通的vector数组来实现邻接表，用DFS进行通路搜索
	//// 在外部初始化邻接表g
	//vector<vector<int>> g;
	//// 用一个vector来记录已经被访问过的点，这样直接解决了重边判断的问题，因为被访问过的点是无法再访问的
	//vector<bool> visited;
	//bool vfindWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
	//	// 初始化两个表,都有n个元素
	//	visited = vector<bool>(n, 0);
	//	g = vector<vector<int>>(n, vector<int>(1, -1));

	//	// 输入数据构造邻接表
	//	for (int i = 0; i < graph.size(); ++i) {
	//		g[graph[i][0]].push_back(graph[i][1]);
	//	}
	//	// 开始递归
	//	return vdfs(start, target);
	//}

	//bool vdfs(int start, int target) {
	//	// 先标定此次迭代的起点被访问过了防止循环
	//	visited[start] = true;
	//	// 循环从1开始因为一开始初始化了一个-1在链表中
	//	for (int i = 1; i < g[start].size(); ++i) {
	//		// 确认是没访问过的结点
	//		if (visited[g[start][i]] == false) {
	//			// 找到时返回
	//			if (g[start][i] == target) {
	//				return true;
	//			}
	//			else {
	//				// 没找到时继续递归，当找到时也返回退出
	//				if (vdfs(g[start][i], target)) {
	//					return true;
	//				}
	//			}
	//		}
	//	}
	//	// 完全没找到则false
	//	return false;
	//}

	//// 用邻接表，但是使用map和set的组合来实现,有问题！
	//// 用DFS进行通路搜索
	//// 邻接表
	//map<int, set<int>> g;
	//// 访问表
	//map<int, bool> v;
	//bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
	//	// 填入邻接矩阵
	//	for (int i = 0; i < graph.size(); ++i) {
	//		if (g.count(graph[i][0]) == 0) {
	//			g[graph[i][0]] = set<int>(graph[i][1]);
	//		}
	//		else {
	//			g[graph[i][0]].insert(graph[i][1]);
	//		}
	//		v[graph[i][0]]=false;
	//	}

	//	return dfs(start, target);
	//}

	//bool dfs(int start, int target) {
	//	v[start] = true;
	//	auto next = (g.find(start))->second;
	//	for (auto iter = next.begin(); iter != next.end(); ++iter) {
	//		if (v[*iter] == false) {
	//			if (*iter == target) {
	//				return true;
	//			}
	//			else {
	//				if (dfs(*iter, target)) {
	//					return true;
	//				}
	//			}
	//		}
	//	}
	//	return false;
	//}

public:
	//LeetCode上比较快的方法,单函数,用队列进行了反向的广度优先搜索
	//避免了对图的二次处理和反复的函数调用,364ms,85.05%
	bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
		// 标记是否访问的链表
		vector<bool> v(n, false);
		// 队列
		queue<int> dp;
		// 将终点压入队列作为反向搜索的起点
		dp.push(target);
		while (!dp.empty())
		{
			// 将队列最前一个取出
			int val = dp.front();
			dp.pop();
			// 若队头与起点相同，代表此时伪终点与起点连接，也就是存在一条路径到达(且最短)终点，返回结果
			if (val == start) return true;
			// 判断是否已经访问过
			if (v[val] == true) continue;
			// 设置访问标记
			v[val] = true;
			// 直接遍历原图，找到每一个与当前终点连接的点
			for (int i = 0; i < n; ++i)
			{
				// 将这个点压入队列末尾作为新的终点，能与这个点相连的点都与终点相连
				if (graph[i][1] == val) 
					dp.push(graph[i][0]);
			}
		}
		return false;
	}
};