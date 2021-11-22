


//leetcode:https ://leetcode-cn.com/problems/decode-ways/

//通过对0情况的讨论,用dp[i]表示前i个元素的解码方法数
//
//1.当遍历所在处为不为0，前一位不为0，且不大于26，
//那么dp[i] = dp[i - 1] + dp[i - 2]
//(dp[i - 1]为将该位置单独一组的情况，dp[i - 2]为其与前一个相连情况)
//2.当开头为0时，必无解码方法
//3.当遍历所在处为0，但前面一位大于2或者前一处为0，那么无解码方法
//4.当遍历所在处为0，且前面一位小于3，那么dp[i]=dp[i-2](因为0不能单独一组)
//5.当遍历所在处不为0，但前面一位为0，那么dp[i]=dp[i-1]
//6.当遍历所在处与前面一位组合的数字大于26，那么dp[i]=dp[i-1]
//最后结果即为dp[s.length()];




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