
static const auto __ = []() // 最大子序列问题
{
ios::sync_with_stdio(false);
// sync_with_stdio(false)是为了打断iostream输入输出到缓存，可以节约很多时间，使之与scanf相差无几。
cin.tie(nullptr);
// tie是将两个stream板顶的函数，空参数的话返回当前的输出指针，即tie(0)与tie(nullptr)来解决cin与cout的绑定。
return nullptr;
}();

class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void reverse(vector<int>& nums,int i){
        int s = i, j = nums.size() - 1;
        while(s < j){
            swap(nums, s , j);
            s++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size();
        if(i < 2) return;
        i -= 2;
        while(i >= 0 && nums[i+1] <= nums[i]){
            i--;
        }
        if(i >= 0){
            int j = nums.size()-1;
            while(j >= 0 && nums[j] <= nums[i]){
                j--;
            }
            swap(nums, i , j);
        }
        reverse(nums,i+1);
    }
};

/*
next_permutation(nums.begin(),nums.end());
这一行代码可以直接搞定整个函数，但是效率比较低
*/