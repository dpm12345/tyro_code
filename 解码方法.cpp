


//leetcode:https ://leetcode-cn.com/problems/decode-ways/
//通过对0情况的讨论



class Solution {
public:
	int numDecodings(string s) {
		vector<int>dp(s.length() + 1);
		dp[0] = 1; dp[1] = 1;
		if (s[0] == '0') return 0;
		for (int i = 2; i <= s.length(); i++)
		{
			if (s[i - 1] = '0'&&s[i - 2]>'2')return 0;
			else if (i>2 && s[i - 1] = '0'&&s[i - 2] != '0')dp[i] = dp[i - 2];
			else if (i == 2 && s[i - 1] = '0'&&s[i - 2] != '0')dp[i] = dp[i - 1];
			else if (s[i - 2] = '0'&&s[i - 1] = '0')return 0;
			else if (s[i - 2] = '0')dp[i] = dp[i - 1];
			else if ((s[i - 2] - 48) * 10 + (s[i - 1] - 48)>26)dp[i] = dp[i - 1];
			else dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[s.length()];
	}
};