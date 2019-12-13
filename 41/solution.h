class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int res = 1,i = 0,size = nums.size();
        for(;i<size;i++){
            if(nums[i] <= 0)
                continue;
            if(nums[i] == res)
                res++;
            if(nums[i] > res)
                return res;
        }
        return res;
    }
};