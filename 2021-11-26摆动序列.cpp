
//摆动序列     https://leetcode-cn.com/problems/wiggle-subsequence/

//1.动态规划

//思路:关键点在于，当增添一个数成为摆动序列中的一个元素时，那么这个数要么小于，要么大于其前面的一个数
//     其大于或小于取决于前面一个数与再前面一个数之间的大小关系
//     就此，可利用动态规划的思想,分别用up[i],down[i]记录前i+1个数的最长摆动序列,
//     (其中up[i]记录末尾为上升的，down[i]记录下降的)
//         将题目解决方法转换为三方面：
//        (1)当nums[i]<nums[i-1]时，该元素不可添加到up[i]中，
//           而对于down,取down[i-1](不加上该数),up[i-1]+1(加上该数)中的最大值
//        (2)当nums[i]>nums[i-1]时，该元素不可添加到down[i]中，
//           而对于up[i],取up[i-1](不加上该数),down[i-1]+1(加上该数)中的最大值
//        (3)当nums[i]=nums[i-1]时，都不能加上,故up[i]=up[i-1],dowm[i]=down[i-1];

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return n;
		vector<int>up(n), down(n);
		up[0] = down[0] = 1;
		for (int i = 1; i<n; i++)
		{
			if (nums[i]<nums[i - 1])
			{
				up[i] = up[i - 1];
				down[i] = max(down[i - 1], up[i - 1] + 1);
			}
			else if (nums[i]>nums[i - 1])
			{
				up[i] = max(up[i - 1], down[i - 1] + 1);
				down[i] = down[i - 1];
			}
			else
			{
				up[i] = up[i - 1];
				down[i] = down[i - 1];
			}
		}
		return max(up[n - 1], down[n - 1]);
	}
};


//空间优化，由于up[i],down[i]只与下标为i-1的值有关，那么可以用两个变量代替数组,最后取这两个变量的最大值

//优化代码如下

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return n;
		int up = 1, down = 1;
		for (int i = 1; i<n; i++)
		{
			if (nums[i]<nums[i - 1])
			{
				down = max(down, up + 1);
			}
			else if (nums[i]>nums[i - 1])
			{
				up = max(up, down + 1);
			}
		}
		return max(up, down);
	}
};


//2.贪心算法

//代码如下


class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return n;
		}
		int prevdiff = nums[1] - nums[0];
		int num = prevdiff != 0 ? 2 : 1;
		for (int i = 2; i < n; i++) {
			int diff = nums[i] - nums[i - 1];
			if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
				num++;
				prevdiff = diff;
			}
		}
		return num;
	}
};

//一开始本身的疑点：其代码行只要有(diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)情况出现，则num++,
//                  不会导致因为所选数不是最佳方案而造成答案错误吗？
//经过思考:  正因为代码段
//                      int diff = nums[i] - nums[i - 1];
//                      if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
//	                        num++;
//	                        prevdiff = diff;
//                      }
//                      每次都会更新diff的值，也就是说每次都会更新“峰”或“谷”的值,从而使得为最佳方案

