

//下降路径最小和      https://leetcode-cn.com/problems/minimum-falling-path-sum/

//思路:由题意知，到达某一位置只能有在上一行中与它纵坐标相差1内
//     的位置到达，那么显然这题使用动态规划
//     其转移方程即为dp[i][j]=min{dp[i-1][j],dp[i-1][j],dp[i-1][j+1]}
//


class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>>dp(m, vector<int>(n));
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (i == 0)
				{
					dp[i][j] = matrix[i][j];
				}
				else if (j == 0)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
				}
				else if (j == n - 1)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + matrix[i][j];
				}
			}
		}
		return *min_element(dp[m - 1].begin(), dp[m - 1].end());

	}
};




//空间优化，使用一个一位数组
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int>dp(n + 2);              //确保每个位置都是min{dp[i-1],dp[i],dp[i+1]};
		int last;                        //last记录上一个变换的dp[i];
		for (int i = 0; i<m; i++)
		{
			dp[0] = dp[n + 1] = INT_MAX;
			last = dp[0];
			for (int j = 0; j<n; j++)
			{
				int temp = dp[j + 1];
				dp[j + 1] = min(last, min(dp[j + 1], dp[j + 2])) + matrix[i][j];             
				//由于把原来数组增加了两个位置，
			    //所以记录dp时只需更新下标1~n+1的dp值
				last = temp;
			}
		}
		return *min_element(dp.begin(), dp.end());

	}
};