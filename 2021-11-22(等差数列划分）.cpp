


//�Ȳ����л���(leeetcode)   https://leetcode-cn.com/problems/arithmetic-slices/



//1.��ѧ����
//��Ҫ�������ף����дӳ���3��ʼ��ÿ����һ��Ԫ�أ��������2��ʼ�ӣ�һ�μ�2��3��4...

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
