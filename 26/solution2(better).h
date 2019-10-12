class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int size = 0;
        for(int i = 1; i < nums.size() ; ++i){
            if(nums[i] != nums[size]){
                ++size;
                nums[size]=nums[i];
            }
        }
        return size+1;
    }
};