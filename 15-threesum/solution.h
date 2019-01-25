class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); 
        if (nums.size() <3|| nums.back() < 0 || nums.front() > 0) return {}; 
        for (int k = 0; k < nums.size()-2; ++k) 
        {
            if (nums[k] > 0) break;                                      
            if (k > 0 && nums[k] == nums[k - 1]) continue; 
            int target = 0 - nums[k]; 
            int i = k + 1, j = nums.size() - 1;
            while (i < j) 
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back({nums[k], nums[i], nums[j]}); 
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j; 
                } 
                else if (nums[i] + nums[j] < target) 
                        ++i;
                else --j;
            }
        }
        return res; 
    }
};
/*
 整理数组，其实这里可以加上不重复超过两次，0除外
 通过分区正负来剪枝
 然后选定目标，（通过判目标是否相等剪枝）
 双指针+去重
 */
