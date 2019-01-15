class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int x[256];
        int num = 0;
        int max_num = 0;
        memset(x,-1,sizeof(x));
        for (int i = 0; i < s.length(); ++i)
        {
            if (x[ s[i] + 128 ] == -1)
            {
                x[ s[i] + 128 ] = i;
                ++num;
            }
            else
            {
                for (int j = 0; j < 256; ++j)
                {
                    if ( x[j] < x[ s[i] + 128 ] )
                    {
                        x[j] = -1;
                    }
                }
                num = ( i - x[ s[i] + 128 ] );
                x[ s[i] + 128 ] = i;
            }
            max_num = max(num, max_num);
        }
        return max_num;
    }
};
