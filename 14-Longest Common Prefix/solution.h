class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string re = strs[0];
        for(int i=0 ; i<strs.size() ; ++i)
        {
            int num;
            if(re.size()>strs[i].size())
            {
                re.substr(0,strs[i].size());
                num = strs[i].size();
            }
            else num = re.size();
            int j=0;
            for(; j<re.size() ; ++j)
            {
                if(re[j]!=strs[i][j]) break;
            }
            re = re.substr(0,j);
        }
        return re;
    }
};
