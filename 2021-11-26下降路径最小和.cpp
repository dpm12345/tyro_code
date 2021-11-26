

//�½�·����С��      https://leetcode-cn.com/problems/minimum-falling-path-sum/

//˼·:������֪������ĳһλ��ֻ��������һ�����������������1��
//     ��λ�õ����ô��Ȼ����ʹ�ö�̬�滮
//     ��ת�Ʒ��̼�Ϊdp[i][j]=min{dp[i-1][j],dp[i-1][j],dp[i-1][j+1]}
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




//�ռ��Ż���ʹ��һ��һλ����
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int>dp(n + 2);              //ȷ��ÿ��λ�ö���min{dp[i-1],dp[i],dp[i+1]};
		int last;                        //last��¼��һ���任��dp[i];
		for (int i = 0; i<m; i++)
		{
			dp[0] = dp[n + 1] = INT_MAX;
			last = dp[0];
			for (int j = 0; j<n; j++)
			{
				int temp = dp[j + 1];
				dp[j + 1] = min(last, min(dp[j + 1], dp[j + 2])) + matrix[i][j];             
				//���ڰ�ԭ����������������λ�ã�
			    //���Լ�¼dpʱֻ������±�1~n+1��dpֵ
				last = temp;
			}
		}
		return *min_element(dp.begin(), dp.end());

	}
};