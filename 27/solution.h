class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] == val){
                size --;
                int tmp = nums[size];
                nums[size] = nums[i];
                nums[i] = nums[size];
                --i;
            }
        }
        return size;
    }
};

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int temp = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != val){
                nums[temp] = nums[i];
                temp++;
            }
        }
        return temp;
    }
};