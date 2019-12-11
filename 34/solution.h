class Solution {
public:
    int find(vector<int>& nums, int target, int left, int right,int i){
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        if(left == right || right == 1 || left == nums.size()-1) 
            return -1;
        int pivot = (left + right)/2;
        if(nums[pivot] == target) return pivot;
        if(nums[pivot] < target){
            left = pivot + 1;
        }else{
            right = pivot - 1;
        }
        return find(nums, target, left, right, i+1);
    } 
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr(2,-1);
		if (nums.empty()) 
			return arr;
        else if(nums.size() == 1){
            if(nums[0] == target){
                arr[0] = 0, arr[1] = 0;
            }
            return arr;
        }
		else {
			int t = find(nums, target, 0, nums.size()-1, 0);
            if(t == -1)
                return arr;
            int i;
            bool triger = false;
            for(i = t; i >= 0; i--){
                if(nums[i] != target){
                    triger = true;
                    break;
                }                    
            }arr[0] = i+1;
            triger = false;
            for(i = t; i < nums.size(); i++ ){
                if(nums[i] != target){
                    triger = true;
                    break;
                }    
            }arr[1] = i-1;
		}
		res:return arr;
    }
};