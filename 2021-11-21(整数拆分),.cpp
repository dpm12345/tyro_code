
//�������(leeetcode)   https://leetcode-cn.com/problems/integer-break/
//��ѧ����֤���˻����ʱ���������ն����Էֽ�Ϊ���ɸ�3�����ɸ�2����3�ĸ��������ܶ�




class Solution {
public:
	int integerBreak(int n) {
		if (n == 2)return 1;
		if (n == 3)return 2;
		int num_3 = n / 3, num_2 = (n % 3) / 2;
		if (n % 3 == 1)
		{
			num_3--;
			num_2 += 2;
		}
		return pow(3, num_3)*pow(2, num_2);
	}
};
