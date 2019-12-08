class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()<1 || s.size()<1 || s.size() < words[0].size()*words.size()) return res;
        int wordLen = words[0].size(), lens = wordLen*words.size(), target = 0, cur = 0;
        unordered_map<string,int> allWord;
        for(auto& it:words){
            allWord[it]++;
            for(auto& i:it) target += i;
        }
        for(int i=0; i<lens; i++) cur += s[i];
        // 先看当前字符串的 ASCII 码相加是否相等 方便去重
        for(int i=0, j; i<=s.size()-lens; cur -= s[i], cur += s[lens + i++]){
            // 快速去重
            if(cur != target) continue;
            // 确认一下，是否为真的匹配
            unordered_map<string,int> tem(allWord);
            for(j=i; j<i+lens; j+=wordLen)
                if(tem[s.substr(j, wordLen)]-- == 0) break;
            if(j == i+lens) res.push_back(i);
        }
        return res;
    }
};

class SolutionBetter {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return vector<int>();
        
        int w = words[0].size();
        
        typedef unsigned long long ULL;
        
        static ULL f[100010];
        
        const int P = 131;
        ULL base = 1;
        f[0] = 0;
        for(int i = 0 ; i < w ; i++) {
            base *= P;
            f[0] *= P;
            f[0] += s[i];
        }

        for(int i = 1 ; i+w-1 < s.size() ; i++)
            f[i] = f[i-1]*P-s[i-1]*base+s[i+w-1];

        unordered_map<ULL,int> h;
        
        for(auto x:words) {
            ULL t = 0;
            for(auto y:x) {
                t *= P;
                t += y;
            }
            h[t] ++;
        }
        
        vector<int> ans;
        for(int k = 0 ; k < w ; k++) {
            for(int i = k, j = i-(int)(words.size()*w) ; j+w-1<(int)s.size() ; i+=w,j+=w){
                if(i+w-1<s.size() && --h[f[i]]==0) h.erase(f[i]);
                if(j>=0 && ++h[f[j]]==0) h.erase(f[j]);
                if(h.empty()) ans.push_back(j+w);
            }
        }
        return ans;
    }
};
