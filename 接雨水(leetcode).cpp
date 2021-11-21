//����ˮ   https://leetcode-cn.com/problems/trapping-rain-water/


//  ˫ָ��
//˼·��һ��λ���ܽӵ���ˮ��Ϊ������min(leftmax,rightmax)-height
//�ص����ڵ�height[left]<height[right]ʱ��leftmax<rightmax�س���
//��height[left]>=height[right]ʱ��leftmax>=rightmax�س���

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