class Solution {
public:
    vector<vector<int>> res;
    int size;
    void swap(vector<int>& nums, int first, int i){
        if(first == i) return;
        int tmp = nums[first];
        nums[first] = nums[i];
        nums[i] = tmp;
    }
    void backtrack( vector<int>& nums, int first ){

        if(first == size){
            res.push_back(nums);
        }
        for(int i = first; i < size; i++){
            swap(nums,first,i);
            backtrack(nums,first+1);
            swap(nums,first,i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        if(size < 2)  {
            res.push_back(nums);
            return res;
        }
        std::sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
};