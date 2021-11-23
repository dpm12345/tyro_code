

//�˻�С��k��������    https://leetcode-cn.com/problems/subarray-product-less-than-k/




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
			ans += right - left + 1;    //�����������ʣ����ٸ���ʱ������϶���
			//ԭ�����һ�����Ǽӽ����ģ�ǰ������Ѿ���ǰ������мӽ�ȥ�˹�ֻ�����������һ�����������������ʣ����
		}
		return ans;
	}
};