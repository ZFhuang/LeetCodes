/*
给定一幅由N × N矩阵表示的图像，其中每个像素的大小为4字节，编写一种方法，将图像旋转90度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //单循环版本,78.1%
    //在循环中完成各个位置的转置，但无法很好地利用空间局部性
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix[0].size();
        //i是层数
        for (int i = 0; i < s / 2; ++i) {
            //j是层内的循环，从i到s-i对称，但是要注意最边缘的在循环中操作了所以边缘是 s - i - 1
            for (int j = i; j < s - i - 1; ++j) {
                //在循环中完成一个位置的全部转置
                int tmp1 = matrix[i][j];
                int tmp2 = matrix[j][s - i - 1];
                int tmp3 = matrix[s - i - 1][s - j - 1];
                int tmp4 = matrix[s - j - 1][i];
                matrix[j][s - i - 1] = tmp1;
                matrix[s - i - 1][s - j - 1] = tmp2;
                matrix[s - j - 1][i] = tmp3;
                matrix[i][j] = tmp4;
            }
        }
    }

    //双循环版本,78.1%
    //利用了 右旋=主对角线交换+行轴对称交换 得到
    //矩阵的初等变换又只有行列互换和加减，好像没有与对角线有关的啊
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //先利用双循环来将矩阵按主对角线交换
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //再对每行的元素按照中间对称轴交换
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        return;
    }
};