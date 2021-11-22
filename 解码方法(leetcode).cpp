


//leetcode:https ://leetcode-cn.com/problems/decode-ways/

//ͨ����0���������,��dp[i]��ʾǰi��Ԫ�صĽ��뷽����
//
//1.���������ڴ�Ϊ��Ϊ0��ǰһλ��Ϊ0���Ҳ�����26��
//��ôdp[i] = dp[i - 1] + dp[i - 2]
//(dp[i - 1]Ϊ����λ�õ���һ��������dp[i - 2]Ϊ����ǰһ���������)
//2.����ͷΪ0ʱ�����޽��뷽��
//3.���������ڴ�Ϊ0����ǰ��һλ����2����ǰһ��Ϊ0����ô�޽��뷽��
//4.���������ڴ�Ϊ0����ǰ��һλС��3����ôdp[i]=dp[i-2](��Ϊ0���ܵ���һ��)
//5.���������ڴ���Ϊ0����ǰ��һλΪ0����ôdp[i]=dp[i-1]
//6.���������ڴ���ǰ��һλ��ϵ����ִ���26����ôdp[i]=dp[i-1]
//�������Ϊdp[s.length()];




class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0')
			return 0;
		vector<int>dp(s.length() + 1);
		dp[0] = 1; dp[1] = 1;
		for (int i = 2; i <= s.length(); i++)
		{
			if (s[i - 1] == '0'&&s[i - 2] == '0' || s[i - 1] == '0'&&s[i - 2]>'2')
				return 0;
			else if (s[i - 1] == '0'&&s[i - 2]<'3')
				dp[i] = dp[i - 2];
			else if (s[i - 1] != '0'&&s[i - 2] == '0')
				dp[i] = dp[i - 1];
			else if ((s[i - 1] - 48) + (s[i - 2] - 48) * 10>26)
				dp[i] = dp[i - 1];
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[s.length()];
	}
};