class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        bool flag = true;
        for(int i=0;i<nums.size()&&flag;++i)
        {
            result.push_back(i);
            for(int j=i+1;j<nums.size()&&flag;++j)
            {
                if(nums[i]+nums[j] == target)
                {
                    result.push_back(j);
                    flag=false;
                }
            }
            if(flag) result.pop_back();
        }
        
      return    result;
    }
};
