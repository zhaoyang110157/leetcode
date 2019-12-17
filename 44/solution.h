class Solution {
public:
/*
    vector<int> locS;
    vector<int> locQ;
    void locpSQ(string p){
        for(int i = 0; i < p.length() ; i++){
            if(p[i] == '*')
                locS.push_back(i);
            if(p[i] == '?')
                locQ.push_back(i);
        }
    }
    bool isMatch(string s, string p) {
        if(s == "")
            return p == "";
        if(p == "")
            return false;
        locpSQ(p);
        int locs = 0, locp = 0, sizeS = s.length(), sizeP = s.length();
        for(;locs < sizeS; s++){

        }
    }*/
    bool isMatch(string s,string p){
        int j=0;
	for(int star=0,i=0, last=0;i<s.length();){
		if(j<p.size() && (s[i]==p[j] || p[j]=='?')){
			++i;
			++j;}
		else if(j<p.size() && p[j]=='*'){
			last=i;
			star=++j;}
		else if(star!=0){
			i=++last;
			j=star;}
		else return 0;
		}
		for(; j<p.size() && p[j]=='*'; ++j);
		return j==p.size();
    }
     

};