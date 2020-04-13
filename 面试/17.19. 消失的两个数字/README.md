# 题目

![img](./image/q.png)



# 算法

```python

```

```c++
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<int> res;
       int size = nums.size(), loc = 0,dif = 1;
       if(size == 1){
           if(nums[0] == 1){
               res.push_back(2);
               res.push_back(3);
           }else if(nums[0] == 2){
               res.push_back(1);
               res.push_back(3);
           }else{
               res.push_back(1);
               res.push_back(2);
           }
           return res;
       }
       while(loc < size){
           if(nums[loc]!= loc+dif){
               res.push_back(loc+dif);
               dif ++;
               loc--;
               if(res.size() == 2)
                break;
           }
           loc++;
       }
       if(res.size() == 0){
           res.push_back(nums[size-1]+1);
           res.push_back(nums[size-1]+2);
       }
       if(res.size() == 1){
           res.push_back(nums[size-1]+1);
       }
       return res;
    }
};
```

针对性的三个算法！

1、可以通过求和得到两个缺失的数的和，然后缩小范围

2、通过异或的方法。 A^B^A = B利用这个可以最后得到缺失的两个数的异或，则可以得到差值

```c++
-> 找到缺失的两个数

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n + 2; i ++) ans ^= i;
        for (auto x: nums) ans ^= x;

        int one = 0;
        int diff = ans & -ans; 
        for (int i = 1; i <= n + 2; i ++)
            if (diff & i)
                one ^= i; // ?
        for (auto x: nums)
            if (diff & x) 
                one ^= x;
        return {one, one ^ ans};
    }
};
```







https://leetcode-cn.com/problems/missing-two-lcci/solution/zhuan-zhi-xiao-shi-de-shu-de-san-chong-jie-fa-by-w/