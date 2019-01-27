class Solution{
private:
	static string str[10];
	vector<string> res;
public:
	vector<string> letterCombinations(string digits) {
		
		if(digits.empty())
			return res;
		string str;
		Combine(digits,0,str);
		return res;
	}
 
	void Combine(string &digits,int i,string s){
		if(i>=digits.size())
		{
			res.push_back(s);
			return;
		}
		//输入的数字对应的字符串
		string ss=str[digits[i]-'0'];
		for(int j=0;j<ss.size();j++)
			Combine(digits,i+1,s+ss[j]);
	}
};
 
string Solution::str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

/*
采用静态变量简化函数
  同时财通string 组的方式，简化方式
  第一次做的时候，用的vector， 后来发现vector用的太多了，总是忘了基本的东西
  */
