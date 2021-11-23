

//乘积小于k的子数组    https://leetcode-cn.com/problems/subarray-product-less-than-k/




class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int left = 0, right = 0;
		int pos = 1, ans = 0;
		for (; right<nums.size(); right++)
		{
			pos = pos*nums[right];
			while (pos >= k&&left <= right)
				pos /= nums[left++];
			ans += right - left + 1;    //计算个数，当剩余多少个数时，则加上多少
			//原因：最后一个数是加进来的，前面的数已经在前面计算中加进去了故只需计算加上最后一个数的情况，即加上剩余数
		}
		return ans;
	}
};