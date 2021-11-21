//接雨水   https://leetcode-cn.com/problems/trapping-rain-water/


//  双指针
//思路：一个位置能接的雨水数为其两边min(leftmax,rightmax)-height
//重点在于当height[left]<height[right]时，leftmax<rightmax必成立
//当height[left]>=height[right]时，leftmax>=rightmax必成立

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int leftmax = 0, rightmax = 0, ans = 0;
		while (left<right)
		{
			leftmax = max(leftmax, height[left]);
			rightmax = max(rightmax, height[right]);
			if (height[left]<height[right])
			{
				ans += leftmax - height[left];
				left++;
			}
			else
			{
				ans += rightmax - height[right];
				right--;
			}
		}
		return ans;

	}
};