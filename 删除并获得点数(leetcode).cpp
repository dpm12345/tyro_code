
删除并获得点数
//题目链接https://leetcode-cn.com/problems/delete-and-earn/

//利用dp[i]进行动态规划
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 1)return nums[0];
		vector<int>a(*max_element(nums.begin(), nums.end()) + 1);
		a[0] = 0;
		for (int i = 0; i<nums.size(); i++)            //将每种数字对应的总值计算出，思想类似与leetcode打家劫舍题
		{
			a[nums[i]] += nums[i];
		}
		vector<int>dp(a.size());
		int ans = 0; dp[0] = 0; dp[1] = a[1];
		for (int i = 2; i<a.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);              //因为每次删除一个点n时，还需删去n-1和n+1，
			                                                       //故dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		    ans = max(ans, dp[i]);
		}
		return ans;

	}
};

//空间优化方案

相较于前种，优化将dp[i]数组去掉，换用两个变量
原因为dp[i]的值只与它的前两个值相关，故此前面所计算的值都变成无用，
那么就可以采用类似于斐波那契数列的做法，分别用两个变量记录前两个的数值，
不断更新以该位置为结束点的最大值

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 1)return nums[0];
		vector<int>a(*max_element(nums.begin(), nums.end()) + 1);
		a[0] = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			a[nums[i]] += nums[i];
		}
		int ans = 0, mx1 = a[0], mx2 = max(a[0], a[1]);
		for (int i = 2; i<a.size(); i++)
		{
			int tmp = mx2;
			mx2 = max(mx2, mx1 + a[i]);
			mx1 = tmp;
		}
		return mx2;

	}
};