class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size()<2 || numRows == 1) return s;
        int num = numRows*2 - 2;
        int numline = numRows - 1;
        string result="";
        for(int i=0;i<s.size()/num+1;i++)
        {
            if(i*num < s.size())
            result+=s[i*num];
        }
        int j=1;
        while(j<numRows-1)
        {
            for(int i=0;i<s.size()/num+1;i++)
            {
                if(i*num+j < s.size())
                result+=s[i*num+j];
                if((i+1)*num-j < s.size())
                result+=s[(i+1)*num-j];
            }
            ++j;
        }
        for(int i=0;i<s.size()/num+1;i++)
        {
            if(i*num+numRows-1 < s.size())
            result+=s[i*num+numRows-1];
        }
        return result;
    }
};
