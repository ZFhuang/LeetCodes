/*
���������ַ��� s1 �� s2�����дһ������ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ�����

ʾ�� 1��

����: s1 = "abc", s2 = "bca"
���: true
ʾ�� 2��

����: s1 = "abc", s2 = "bad"
���: false
˵����

0 <= len(s1) <= 100
0 <= len(s2) <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-permutation-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    //��ͳ��������,100%
    //����򵥵�Ԥɸѡ�ӿ��ٶ�
    bool CheckPermutation(string s1, string s2) {
        //�������飬�ǵñ�����sizeof(int)
        int check1[128];
        memset(check1, 0, sizeof(int) * 128);
        int check2[128];
        memset(check2, 0, sizeof(int) * 128);
        //ɸѡ
        if (s1.size() != s2.size())
            return false;
        //���
        for (auto c : s1)
            check1[(int)c] += 1;
        for (auto c : s2)
            check2[(int)c] += 1;
        //��λ�Ա�
        for (int i = 0; i < 128; i++)
            if (check1[i] != check2[i])
                return false;
        return true;
    }
};