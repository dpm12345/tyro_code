
ɾ������õ���
//��Ŀ����https://leetcode-cn.com/problems/delete-and-earn/

//����dp[i]���ж�̬�滮
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 1)return nums[0];
		vector<int>a(*max_element(nums.begin(), nums.end()) + 1);
		a[0] = 0;
		for (int i = 0; i<nums.size(); i++)            //��ÿ�����ֶ�Ӧ����ֵ�������˼��������leetcode��ҽ�����
		{
			a[nums[i]] += nums[i];
		}
		vector<int>dp(a.size());
		int ans = 0; dp[0] = 0; dp[1] = a[1];
		for (int i = 2; i<a.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);              //��Ϊÿ��ɾ��һ����nʱ������ɾȥn-1��n+1��
			                                                       //��dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		    ans = max(ans, dp[i]);
		}
		return ans;

	}
};

//�ռ��Ż�����

�����ǰ�֣��Ż���dp[i]����ȥ����������������
ԭ��Ϊdp[i]��ֵֻ������ǰ����ֵ��أ��ʴ�ǰ���������ֵ��������ã�
��ô�Ϳ��Բ���������쳲��������е��������ֱ�������������¼ǰ��������ֵ��
���ϸ����Ը�λ��Ϊ����������ֵ

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