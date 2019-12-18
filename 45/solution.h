class Solution {
public:
/*dp 
    int size;
    int jump(vector<int>& nums) {
        size = nums.size();
        int* res = new int[size];
        int tmp = 0;
        for(int i = 0; i < size; i++){
            res[i] = size;
        }
        //return tmp;
        for(int i = 0; i < size; i++){
            int tmp = nums[i];
            for(int j = tmp; j >= 1; j--){
                res[j+i] = (res[j+i] < res[i]+1) ? res[j+i] : (res[i] + 1);
            }
        }
        return res[size - 1];
    }*/
    int jump(vector<int>& nums){
        int ans = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(nums[i] + i, maxPos);
            if (i == end)
            {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};