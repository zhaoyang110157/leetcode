# 题目

![img](./image/q.png)
![img](./image/q.png)

# 算法

```python

```

```c++
class Solution {
public:
    vector<int> getModifiedArray0(int length, vector<vector<int>>& updates) {
        vector<int> res = vector(length,0);
        int size = updates.size();
        for(int i = 0; i < size; i++){
            int start = updates[i][0], end = updates[i][1], index = updates[i][2];
            while(start <= end){
                res[start] += index;
                start++;
            }
        }
        return res;
    }//超过时间限制
    
    
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //递增思维
        vector<int> dp(length+1, 0);
        vector<int> ans(length, 0);
        for (int i = 0; i < updates.size(); i++){
            dp[updates[i][0]] += updates[i][2];
            dp[updates[i][1] + 1] -= updates[i][2];
        }
        ans[0] = dp[0];
        for (int i =1; i< length; i++){
            ans[i] = ans[i-1] + dp[i];
        }
        return ans;
    }
};
```

