//接雨水   https://leetcode-cn.com/problems/trapping-rain-water/


//总体方向：一个位置能接的雨水取决于其两侧的最大高度的最小值减去该位置的高度



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



 
//动态规划     与双指针相类似
//                           先找出每个位置的左侧最大高度和右侧的最大高度；
//                           再最后遍历所有位置，计算接水的量并加到ans里

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0) {
			return 0;
		}
		vector<int> leftMax(n);
		leftMax[0] = height[0];
		for (int i = 1; i < n; ++i) {
			leftMax[i] = max(leftMax[i - 1], height[i]);
		}

		vector<int> rightMax(n);
		rightMax[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			rightMax[i] = max(rightMax[i + 1], height[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += min(leftMax[i], rightMax[i]) - height[i];
		}
		return ans;
	}
};




//单调栈   




class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		stack<int> stk;
		int n = height.size();
		for (int i = 0; i < n; ++i) {
			while (!stk.empty() && height[i] > height[stk.top()]) {            //当栈不为空，且当前位置高度大于栈顶位置的高度
				int top = stk.top();
				stk.pop();
				if (stk.empty()) {                    //若pop后变为空，那么该栈中只有一个元素，也就是说接不到雨水，那么可将该位置删除
					                                  //反之，若pop后不为空，那么栈中至少有两个元素，栈顶的前一个元素left必满足
					                                  //height[left]>=height[top],也就是说height[left]就是上面方法的leftmax[i],height[top]为
					                                  //height[i],height[i]为rightmax[i]
					break;
				}
				int left = stk.top();
				int currWidth = i - left - 1;                     //由于是通过栈实现，每次计算都只计算一行，那么需要计算其长度
				int currHeight = min(height[left], height[i]) - height[top];                
				ans += currWidth * currHeight;
			}
			stk.push(i);                         //放入位置下标
		}
		return ans;
	}
};