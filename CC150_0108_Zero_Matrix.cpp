/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zero-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //原位标记染色法，以时间换空间，28.7%
    //用-65535来标记被清除的部分，之前写国际象棋判断有遇到
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        //为0时设为-65535来标记，-65535只是一个比较特殊的标记数而已
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    setNegOne(matrix, i, j);
                }
            }
        }
        //将标记部分设为0
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == -65535) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //用于将数组对应的行列标记
    void setNegOne(vector<vector<int>>& matrix, int y, int x) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if ((i == y || j == x) && matrix[i][j] != 0) {
                    matrix[i][j] = -65535;
                }
            }
        }
    }

    //额外列表法，空间换时间,88.4%
    //用一个额外的列表来记录哪些行列需要清除，然后最后再一次性清除
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        //行列标记向量
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    //检测到0时，将需要清除的行列记录下来
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                //第二次循环时将有记录的行列清0
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
    }
};