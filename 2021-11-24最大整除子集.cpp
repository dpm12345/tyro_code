
//最大整除子集    https://leetcode-cn.com/problems/largest-divisible-subset/

//思路：动态规划思想            2021-11-24



//第一步，找最大整除子集的长度及该子集内的最大值.
//    类似于贪心算法中找最大不连续上升(下降)子序列dp[i]=max(dp[i],d[j]+1)

//第二步，从后往前找最大整除子集的各项元素  maxsize 代表该子集的长度，maxval 代表该子集中的最大元素
//   方法：因为最大整除子集必满足相邻两个必整除为0，那么在判断是否为该子集元素时，
//         可通过  maxval % nums[i] == 0  和 maxsize==dp[i](用于判断是否为最大整除数的一列里,当满足该条件时
//         将元素存入输出数组中，并将  maxsize  减一,为下一步判断提供条件）进行判断


class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int>dp(nums.size(), 1);
		int maxsize = dp[0], maxval = nums[0];
		for (int i = 1; i<nums.size(); i++)                //找最大整除子集的长度及该子集内的最大值
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
		vector<int>ans;                     //从后往前找寻最大整除子集的各元素
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