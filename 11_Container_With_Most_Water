/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

class Solution {
public:
    //95.17%
    int maxArea(vector<int>& height) {
        //滑动窗口法，保持长的一边不动，因为从外往内缩小底面时，只有遇到更长的木板才可能使得桶容量变大
        int left=0,right,h=0,max=0,temp=0;
        right=height.size()-1;
        while(true){
            if(height[left]<height[right]){
                h=height[left];
                left++;
            }
            else{
                h=height[right];
                right--;
            }
            temp=(right-left+1)*h;
            if(temp>max){
                max=temp;
            }
            if((right-left+1)<=1){
                break;
            }
        }
        return max;
    }
};
