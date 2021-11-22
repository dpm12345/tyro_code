

//两个数组的交集

//思路，利用map记录数组长度较长的内部出现数字及个数
//最后遍历数组长度较小的数组
//如果在map找到该元素，则该元素个数减一，若个数减为0，可将该元素删除

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