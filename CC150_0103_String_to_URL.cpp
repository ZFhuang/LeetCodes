/*
URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ%20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ���ע����Javaʵ�ֵĻ�����ʹ���ַ�����ʵ�֣��Ա�ֱ���������ϲ�������

ʾ��1:

 ���룺"Mr John Smith    ", 13
 �����"Mr%20John%20Smith"
ʾ��2:

 ���룺"               ", 5
 �����"%20%20%20%20%20"
��ʾ��

�ַ���������[0, 500000]��Χ�ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/string-to-url-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    //��ͳ����,82.3%
    //���ı����ַ������뵽�µ�������,�ǵý�βҪ��һ��������
    string replaceSpaces(string S, int length) {
        //����ΪĿ���ַ���+1,ʡ���ڴ�
        char* newString = new char[S.size() + 1];
        int cursor = 0;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') {
                newString[cursor] = '%';
                newString[cursor + 1] = '2';
                newString[cursor + 2] = '0';
                cursor += 2;
            }
            else {
                newString[cursor] = S[i];
            }
            cursor++;
        }
        //������
        newString[cursor] = '\0';
        //string��ָ�빹��
        //string(const char * s, size_type n)
        return string(newString, S.size() + 1);
    }

    //�����Ż�,100%
    //�ر���ͬ��+ʹ���ַ���ƴ��
    string replaceSpaces(string S, int length) {
        //����cin��cout��stdin���Ǳ���ͬ���ģ������кܴ�������ʧ
        //�����ر�����ͬ���ӿ�cin��cout��ȡ
        ios::sync_with_stdio(false);
        string str = "";
        for (int i = 0; i < length; i++) {
            //ʹ���ַ���ƴ��+=�ŵ�Ч������ߵ�
            if (S[i] == ' ') str += "%20";
            else str += S[i];
        }
        return str;
    }
};