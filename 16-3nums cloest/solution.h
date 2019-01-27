class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int re = 1000000;
        int de = 1000000 ;
        for(int a =  0 ; a < nums.size()-2 ; ++a)
        {
            for(int b = a+1; b < nums.size()-1 ; ++b)
            {
                for(int c = b+1; c < nums.size() ; ++c)
                {
                    int resu = nums[a] + nums[b] + nums[c];
                    int res = target - resu;
                    res = (res > 0)? res:-res ;
                    if(de > res) 
                    {
                        de = res;
                        re = resu;
                    }
                    if(!de) return target;
                }
            }
        }
        return re;
    }
};
