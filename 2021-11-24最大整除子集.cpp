
//��������Ӽ�    https://leetcode-cn.com/problems/largest-divisible-subset/

//˼·����̬�滮˼��            2021-11-24



//��һ��������������Ӽ��ĳ��ȼ����Ӽ��ڵ����ֵ.
//    ������̰���㷨���������������(�½�)������dp[i]=max(dp[i],d[j]+1)

//�ڶ������Ӻ���ǰ����������Ӽ��ĸ���Ԫ��  maxsize ������Ӽ��ĳ��ȣ�maxval ������Ӽ��е����Ԫ��
//   ��������Ϊ��������Ӽ���������������������Ϊ0����ô���ж��Ƿ�Ϊ���Ӽ�Ԫ��ʱ��
//         ��ͨ��  maxval % nums[i] == 0  �� maxsize==dp[i](�����ж��Ƿ�Ϊ�����������һ����,�����������ʱ
//         ��Ԫ�ش�����������У�����  maxsize  ��һ,Ϊ��һ���ж��ṩ�����������ж�


class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int>dp(nums.size(), 1);
		int maxsize = dp[0], maxval = nums[0];
		for (int i = 1; i<nums.size(); i++)                //����������Ӽ��ĳ��ȼ����Ӽ��ڵ����ֵ
		{
			for (int j = 0; j<i; j++)
			{
				if (nums[i] % nums[j] == 0)
				{
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i]>maxsize)
					{
						maxsize = dp[i];
						maxval = nums[i];
					}
				}
			}
		}
		vector<int>ans;                     //�Ӻ���ǰ��Ѱ��������Ӽ��ĸ�Ԫ��
		if (maxsize == 1)
		{
			ans.push_back(maxval);
			return ans;
		}
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (dp[i] == maxsize&&maxval%nums[i] == 0)
			{
				ans.push_back(nums[i]);
				maxval = nums[i];
				maxsize--;
			}
		}
		return ans;
	}
};