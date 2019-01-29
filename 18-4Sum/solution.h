class Solution {
    private:
    int h=10000000;
public:
    bool re(vector<int>& nums,int i,int j, int target)
    {
        for(int k=i+1;k<j;++k)
        {
            if(nums[i]+nums[j]+nums[k] == target)
                return true;
        }
        return false;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); 
        if (nums.size() <4|| nums.back() < 0 || nums.front() > 0) return {}; 
         for (int k = 0; k < nums.size()-3; ++k) {
        if (k > 0 && nums[k] == nums[k - 1]) continue;
        int ntarget = target - nums[k];
        for (int j = k+1; j < nums.size()-2; ++j) {
            if (j > k+1 && nums[j] == nums[j - 1]) continue;
            int nntarget = ntarget - nums[j];
            int m = j + 1, n = nums.size() - 1;
            while (m < n) {
                if (nums[m] + nums[n] == nntarget) {
                    res.push_back({nums[k], nums[j], nums[m], nums[n]});
                    while (m < n && nums[m] == nums[m + 1]) ++m;
                    while (m < n && nums[n] == nums[n - 1]) --n;
                    ++m; --n;
                } else if (nums[m] + nums[n] < nntarget) ++m;
                else --n;
            }   
        }
    }   
        return res; 
    }
};//降阶
