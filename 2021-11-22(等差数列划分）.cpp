


//等差数列划分(leeetcode)   https://leetcode-cn.com/problems/arithmetic-slices/



//1.数学方法
//主要在于明白，数列从长度3开始，每增加一个元素，其个数从2开始加，一次加2，3，4...

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		if (nums.size()<3)return 0;
		int count = 1, ans = 0;
		for (int i = 1; i<nums.size() - 1; i++)
		{
			if (nums[i] * 2 == nums[i - 1] + nums[i + 1])
				ans += count++;
			else count = 1;
		}
		return ans;
	}
};
