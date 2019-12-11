class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 1) return 0;
        int res = 0;
        for(int i = 0; i < size ; i++){
            if(nums[i] == target) return i;
            if(nums[i] < target) res = i+1;
        }
        return res;
    }
};