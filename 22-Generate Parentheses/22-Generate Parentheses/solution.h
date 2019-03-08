#include<string>
#include<set>
#include<vector>
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		set<string> v1;
		v1.insert("()");
		v1 = generate(v1, n, 1);
		vector<string> v;
		for (set<string>::iterator a = v1.begin(); a != v1.end(); ++a)
		{
			v.push_back(*a);
		}
		return v;
	}
	set<string> generate(set<string> v, int target, int now)
	{
		if (target == now) return v;

		set<string> n;
		for (set<string>::iterator a = v.begin(); a != v.end(); ++a)
		{
			string tmp = *a;
			for (int j = 0; j < tmp.size(); j++)
			{
				string ne = tmp.insert(j, "()");
				n.insert(ne);
			}
		}
		now++;
		return generate(n, target, now);
	}
}; #pragma once
