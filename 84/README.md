# 题目

![img](./image/q1.png)
![img](./image/q2.png)

# 算法

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int min = 1, num = 0, res = 0, size = heights.size();
        bool mark = true;
        if(size == 0) return 0;
        if(size == 1) return heights[0];
        while(mark){
            mark = false;
            for(int i = 0; i < size; i++){
                if(heights[i] >= min){
                    num++;
                    mark = true;
                }else{
                    if( num * min > res){
                        res = num * min;                          
                    }
                    num = 0;
                }
            }
            if( num * min > res){
                res = num * min;                          
            }
            num = 0;
            min++;
        }
        return res;
    }
};
/*
	基本思维，自底向上，层层盘剥，问题在于时间复杂度位 O(size*max)
	未对特殊情况进行剪枝， 例如 [0,0,0,0,0,0,2147483647]
	在系统上过不去，下一步尝试进行使用 bool标志的方式来进行剪枝。同时，这就有一个额外的小情况需要考虑，也就是我们现有的体系，是通过隔离（高度达不到）来进行的，这里的判定需要改动一下
*/	
```

```c++
class Solution {
public:
    int max(int a, int b)
    {
        return a>b?a:b;
    }
    int largestRectangleArea(vector<int>& heights) {
        set<int> iset;
        int maxArea = 0;
        for (auto x: heights) iset.insert(x);
        for (auto x: iset)
        {
            int curArea = 0;
            for (auto y:heights)
            {
                if (y>=x) curArea+=x;
                else
                {
                    maxArea = max(maxArea, curArea);
                    curArea = 0;
                }
            }
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};//某种巨慢的操作，但是他过了
/*
	他的优势在于减少了直接的等级增加，通过了set的方式减少了这个过程
*/
```

```c++
class Solution {
public:
    int calculateArea(vector<int>& heights, int start, int end){
        if(start>end)
            return 0;
        int minindex = start;
        for(int i = start; i <= end; i++)
            if(heights[minindex] > heights[i])
                minindex = i;
        int res = heights[minindex] * (end - start + 1);
        int res1 = calculateArea(heights, start, minindex-1);
        int res2 = calculateArea(heights, minindex+1,end);
        res1 = (res1 < res2)?res2:res1;
        return (res1 > res)? res1: res;
    }
    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights,0,heights.size()-1);
    }
    //分治法处理问题，但是时间更慢了？？？？
    /*
    	时间复杂度：O(nlogn)
		空间复杂度：O(n)
    */
};
```



```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {        
        stack<int> st;
        heights.push_back(0);
        int size = heights.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int val = st.top();
                st.pop();
                res = max(res, heights[val] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
//栈方法，最优解？
/*
在这种方法中，我们维护一个栈。一开始，我们把 -1 放进栈的顶部来表示开始。初始化时，按照从左到右的顺序，我们不断将柱子的序号放进栈中，直到遇到相邻柱子呈下降关系，也就是 a[i−1]>a[i]a[i-1] > a[i]a[i−1]>a[i] 。现在，我们开始将栈中的序号弹出，直到遇到 stack[j]stack[j]stack[j] 满足a[stack[j]]≤a[i]a\big[stack[j]\big] \leq a[i]a[stack[j]]≤a[i] 。每次我们弹出下标时，我们用弹出元素作为高形成的最大面积矩形的宽是当前元素与 stack[top−1]stack[top-1]stack[top−1] 之间的那些柱子。也就是当我们弹出 stack[top]stack[top]stack[top] 时，记当前元素在原数组中的下标为 i ，当前弹出元素为高的最大矩形面积为：
(i−stack[top−1]−1)×a[stack[top]].(i-stack[top-1]-1) \times a\big[stack[top]\big].
(i−stack[top−1]−1)×a[stack[top]].
更进一步，当我们到达数组的尾部时，我们将栈中剩余元素全部弹出栈。在弹出每一个元素是，我们用下面的式子来求面积： (stack[top]−stack[top−1])×a[stack[top]](stack[top]-stack[top-1]) \times a\big[stack[top]\big](stack[top]−stack[top−1])×a[stack[top]]，其中，stack[top]stack[top]stack[top]表示刚刚被弹出的元素。因此，我们可以通过每次比较新计算的矩形面积来获得最大的矩形面积。
时间复杂度：O(n)，n 个数字每个会被压栈弹栈各一次。
空间复杂度：O(n)。用来存放栈中元素。
*/
```

