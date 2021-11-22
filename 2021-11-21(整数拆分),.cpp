
//整数拆分(leeetcode)   https://leetcode-cn.com/problems/integer-break/
//数学方法证明乘积最大时，因子最终都可以分解为若干个3和若干个2，且3的个数尽可能多




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
