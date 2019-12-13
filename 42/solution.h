class Solution {
public:
    int trap1(vector<int>& height) {
        map<int,vector<int>> m;
        int max = 0, size = height.size(),res = 0;
        for(int i = 0; i < size; i++){
            if(height[i] > max) max = height[i];
            m[height[i]].push_back(i);
        }
        for(int i = max; i > 0; i--){
            vector<int> tmp = m[i];
            std::sort(tmp.begin(),tmp.end());
            for(int j = 1; j < tmp.size(); j++){
                res += tmp[j]-tmp[j-1]-1;
                //if(i == 3 && j == 1) return res;
                m[i-1].push_back(tmp[j]);
            }
            m[i-1].push_back(tmp[0]);
        }
        return res;
    }
    int trap2(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
    int trap3(vector<int>& height) {
        int hightest = 0;
        int index = 0;
        int result = 0;
        if(height.size()<3)
            return 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i]>hightest)
            {
                index = i;
                hightest = height[i];
            }
        }
        
        int temp = height[0];
        for(int i = 1; i < index; i++)
        {
            if(height[i]<temp)
            {
                result+=temp-height[i];
            }
            else
                temp = height[i];
        }
        temp = height[height.size()-1];
        for(int i = height.size()-1; i >= index; i--)
        {
            if(height[i]<temp)
            {
                result+=temp-height[i];
            }
            else
                temp = height[i];
        }
        return result;
    }
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, h = 0, ans = 0;
        while (l < r)
            if (height[l] < height[r]) 
                (height[l] >= h) ? (h = height[l++]) : (ans += h - height[l++]);
            else 
                (height[r] >= h) ? (h = height[r--]) : (ans += h - height[r--]);
        return ans;
    }
};//依次向下更优