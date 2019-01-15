class Solution {
public:
	int find(char a ,string b)
	{
		for(int i=0;i<b.size();++i)
		{
			if(b[b.size()-1-i] == a) return i;
		}
		return -1;
	}
	int lengthOfLongestSubstring(string s) {
		int loc = 0;
		int max = 0;
		string result="";
		while(loc<s.size())
		{
			int i = find(s[loc],result);
			if(i<0)
			{
				result+=s[loc];
				if(result.size()>max) max = result.size();
			}
			else result = result.substr(result.size()-i)+s[loc];
            loc++;
		}
		return max;
		}
};

