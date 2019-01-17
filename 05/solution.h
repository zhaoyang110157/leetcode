class Solution {
public:
    bool check(string &s,int start,int end)
    {
        bool flag = true;
        while(start < end )
        {
            if( s[start] == s[end])
            {
                ++start;
                --end;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int i = 0;
        string longest=s.substr(0,1);
        while(i < (s.size()-longest.size()))
        {
           
            int tm = s.size()-1;
            while(tm>i)
            {
                if(s[i] == s[tm])
                { 
                    if(check(s,i,tm)) 
                    {
                        if(longest.size() <= tm-i+1)
                        longest = s.substr(i,tm-i+1);
                        break;
                    }
                }
                --tm;
            }
           
            ++i;
        }
        return longest;
    }
};
