/*
ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

ʾ�� 1��

����: s = "leetcode"
���: false
ʾ�� 2��

����: s = "abc"
���: true
���ƣ�

0 <= len(s) <= 100
����㲻ʹ�ö�������ݽṹ����ܼӷ֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/is-unique-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    //ʹ�ñ������,66.6%
    //���������ֱ�ӷ��أ�û���ֵ��ַ������ñ��
    bool isUnique(string astr) {
        int unique[128];
        //leetcode��Ҫ����������Ӧ��������
        memset(unique, 0, sizeof(int) * 128);
        for (char& c : astr) {
            if (unique[c] == 1)
                return false;
            else
                unique[c] = 1;
        }
        return true;
    }

    //��ʹ�ö�������ݽṹ, 60.6%
    //��λ�������������飬���ԣ������Թ٣���֪�ַ�����a-z
    bool isUnique(string astr) {
        //��int����ʶ��ĸ���
        int unique = 0;
        int mask;
        for (char& c : astr) {
            //��λ��������
            mask = 1 << (c - 'a');
            if (unique & mask)
                return false;
            else
                unique |= mask;
        }
        return true;
    }
};