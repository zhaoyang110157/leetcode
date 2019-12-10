class Solution {
public:
    int findpivot(vector<int>&nums, int left, int right){
        if(nums[left] < nums[right]){
            return 0;
        }
        while (left <= right) {
            int pivot = (left + right) / 2;
            if (nums[pivot] > nums[pivot + 1])
                return pivot + 1;
            else {
                if (nums[pivot] < nums[left])
                right = pivot - 1;
                else
                left = pivot + 1;
            }
        }
        return 0;
    } 

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<1) return -1;
        if(n<2) return (nums[0] == target)? 0 :-1;
        int left = 0, right = n-1;
        int pivot = findpivot(nums,left,right);
        
        while(left<=right){
            int tmp = (left+right)/2;
            int t = (tmp + pivot) % n ;
            if(nums[t] == target){
                return t;
            }else{
                if(target < nums[t] ){
                    right = tmp - 1;
                }else{
                    left = tmp + 1;
                }
            }
        }
        return -1;
    }
};