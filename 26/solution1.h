class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for(int i = 1; i < size ; ++i){
            if(nums[i-1] == nums[i]){
                auto item = nums.erase(nums.begin()+i, nums.begin()+i+1);
                --size;
                --i;
            }
        }
        return size;
    }
};