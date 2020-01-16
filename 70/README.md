# 题目

![img](./image/q.png)

# 算法

```
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        long a = 1, b = 2, i = 2, res = 0;
        bool turna = true;
        while(i <= n){
            if(turna){
                a += b;
                turna = false;
            }else{
                b += a;
                turna = true;
            }
            i++;
        }
        return (turna)?a:b;
    }
};
```

此问题实际上是斐波那契数列问题

> f(n) = f(n-1) + f(n-2)

因为这一级需要从下一级或者下下级跨步上来，所以这两级的所有方法和为到这一级的方法。

而后，我的算法实际上使用了通过变换a和b的n-1或者n-2的位置，实现了常数位的算法。