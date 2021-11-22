

//��������Ľ���

//˼·������map��¼���鳤�Ƚϳ����ڲ��������ּ�����
//���������鳤�Ƚ�С������
//�����map�ҵ���Ԫ�أ����Ԫ�ظ�����һ����������Ϊ0���ɽ���Ԫ��ɾ��

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size()>nums2.size())
			return intersect(nums2, nums1);
		vector<int>ans;
		unordered_map<int, int>n;
		for (int i = 0; i<nums2.size(); i++)
		{
			n[nums2[i]]++;
		}
		for (int i = 0; i<nums1.size(); i++)
		{
			if (n[nums1[i]]>0)
			{
				ans.push_back(nums1[i]);
				n[nums1[i]]--;
				if (n[nums1[i]] == 0)
					n.erase(nums1[i]);
			}
		}
		return ans;
	}
};