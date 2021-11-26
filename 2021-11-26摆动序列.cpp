
//�ڶ�����     https://leetcode-cn.com/problems/wiggle-subsequence/

//1.��̬�滮

//˼·:�ؼ������ڣ�������һ������Ϊ�ڶ������е�һ��Ԫ��ʱ����ô�����ҪôС�ڣ�Ҫô������ǰ���һ����
//     ����ڻ�С��ȡ����ǰ��һ��������ǰ��һ����֮��Ĵ�С��ϵ
//     �ʹˣ������ö�̬�滮��˼��,�ֱ���up[i],down[i]��¼ǰi+1��������ڶ�����,
//     (����up[i]��¼ĩβΪ�����ģ�down[i]��¼�½���)
//         ����Ŀ�������ת��Ϊ�����棺
//        (1)��nums[i]<nums[i-1]ʱ����Ԫ�ز�����ӵ�up[i]�У�
//           ������down,ȡdown[i-1](�����ϸ���),up[i-1]+1(���ϸ���)�е����ֵ
//        (2)��nums[i]>nums[i-1]ʱ����Ԫ�ز�����ӵ�down[i]�У�
//           ������up[i],ȡup[i-1](�����ϸ���),down[i-1]+1(���ϸ���)�е����ֵ
//        (3)��nums[i]=nums[i-1]ʱ�������ܼ���,��up[i]=up[i-1],dowm[i]=down[i-1];

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


//�ռ��Ż�������up[i],down[i]ֻ���±�Ϊi-1��ֵ�йأ���ô����������������������,���ȡ���������������ֵ

//�Ż���������

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


//2.̰���㷨

//��������


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

//һ��ʼ������ɵ㣺�������ֻҪ��(diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)������֣���num++,
//                  ���ᵼ����Ϊ��ѡ��������ѷ�������ɴ𰸴�����
//����˼��:  ����Ϊ�����
//                      int diff = nums[i] - nums[i - 1];
//                      if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
//	                        num++;
//	                        prevdiff = diff;
//                      }
//                      ÿ�ζ������diff��ֵ��Ҳ����˵ÿ�ζ�����¡��塱�򡰹ȡ���ֵ,�Ӷ�ʹ��Ϊ��ѷ���

