class Solution {
public:
    bool isMatch(string s, string p) {int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1,false));
		dp[0][0] = true;
 
		for (int i = 0; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (p[j - 1] == '*'){
					dp[i][j] = dp[i][j - 2] ||
						(i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				}
				else{
					if (i > 0 && (s[i-1] == p[j-1] || p[j-1] == '.')){
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
			}
		}
		return dp[m][n];
	
    }
};

/*
This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j)and false otherwise. Then the state equations are:

P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.


原文：https://blog.csdn.net/gao1440156051/article/details/52212918 

*/
