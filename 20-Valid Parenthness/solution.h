class Solution {
private:
    map<char,int> m;
public: 
    Solution(){
        m['('] = 1;
        m[')'] = -1;
        m['{'] = 2;
        m['}'] = -2;
        m['['] = 3;
        m[']'] = -3;
    }

    bool isValid(string s) {
        stack<int> re;
        int i=0;
        while(i<s.size())
        {
            if(m[s[i]]>0)
                re.push(m[s[i]]);
            else{
                if( re.size() == 0 ||re.top()+m[s[i]] ) return false;
                /*
                借用||的简化特性 来处理 直接输入后半符的情况（为了防止出错，因为空的情况下，是没有top的
                */
                else{
                    re.pop();
                }
            }
            ++i;
        }
        if(re.size()) return false;
        else return true;
    }
};
