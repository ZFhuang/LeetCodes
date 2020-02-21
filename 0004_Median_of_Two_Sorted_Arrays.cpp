/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

#include<vector>
#include<iostream>
using namespace std;

int main() {
    Solution s;
    cout << s.findMedianSortedArrays({ 1,2 }, { 3,4 });
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto i = nums1.begin();
        auto j = nums2.begin();
        int mid = (nums1.size() + nums2.size()) / 2 + 1;
        int odd = 0;
        if ((nums1.size() + nums2.size()) % 2 == 1)
            odd = 1;
        int cursor = 0;
        int a, b;
        while (i != nums1.end() || j != nums2.end()) {
            if (i != nums1.end() && (j == nums2.end() || *i <= *j)) {
                a = b; b = *i;
                ++i;
            }
            else if (j != nums2.end() && (i == nums1.end() || *j < *i)) {
                a = b; b = *j;
                ++j;
            }
            if (++cursor == mid)
                break;
        }
        if (odd)
            return b;
        else
            return (a + b) / 2;
    }
};