class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int lhs = 0 ,rhs = height.size()-1;
        while(lhs < rhs)
        {
            int high = min( height[lhs] , height[rhs] );
            area = ( area < (rhs-lhs)*high )? (rhs-lhs)*high : area;
            if(height[lhs] < height[rhs])
                ++lhs;
            else --rhs;
        }
        return area;
    }
};
/*
因为最大盛水量需要依靠宽度和高度，越宽的两个边容器越好，所以采用双指针模式。
又因为依靠最低墙壁来决定高度，所以，采用移动最低墙壁的方法，来尝试获取更大容量。
*/
