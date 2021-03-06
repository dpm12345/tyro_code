class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_map<int,int> Hash;
        for(int i=0;i<len;i++)
        {
            auto it=Hash.find(target-nums[i]);
            if(it!=Hash.end())
            return {it->second,i};
            Hash[nums[i]]=i;
        }
        return {};
    }
};
