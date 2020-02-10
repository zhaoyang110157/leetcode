# 题目

![img](./image/q.png)
![img](./image/q.png)

# 算法

```python

```

```c++
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int loc = 0, cnt = 0, gap = 'A'-'a';
        for(;loc < S.length(); loc ++){
            char tmp = S[loc];
            if(tmp == '-'){
                S.erase(loc,1);
                loc--;
                continue;
            }
            if(cnt == K){
                S.insert(loc,1,'-');
                cnt = 0;
                continue;
            }
            if(tmp >= 'a' && tmp <= 'z'){
                S[loc] += gap;
            }
            cnt++;
        }
        cout<<cnt;
        if(cnt != 0 && cnt != K){
            cnt = K - cnt;
            for(loc = 0;loc < S.length(); loc ++){
                char tmp = S[loc];
                if(tmp == '-'){
                    S.erase(loc,1);
                    loc--;
                    continue;
                }
                if(cnt == K){
                    S.insert(loc,1,'-');
                    cnt = 0;
                    continue;
                }
                cnt++;
            }
        } 
        return S;
        //因为两边所以时间会很大，但是相对的，我们的空间很小。
    	//采用从首到尾的遍历方式，缺少的空间，在第二次遍历的时候解决。
    }
    string licenseKeyFormatting1(string S, int K) {
        int loc = S.length() - 1, cnt = 0, gap = 'A' - 'a';
        string res = "";
        for(;loc >= 0; loc--){
            if(cnt == K){
                res = "-" + res;
                cnt = 0;
            }
            char tmp = S[loc];
            if(tmp == '-')
                continue;
            if(tmp >= 'a' && tmp <= 'z')
                tmp += gap;
            res = tmp + res;
            cnt++;
        }
        if(res[0] == '-')
            res.erase(0,1);
        return res;
        //失败品，原因空间不够！
        //直接收集，整合不动脑子的解法。
    }
    string licenseKeyFormatting2(string s, int K) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        int loc = s.length() - 1, cnt = 0;
        for(; loc >= 0; loc--){
            //cout<<"loc "<<loc<<" cnt "<<cnt<<" s "<<s<<endl;
            if(cnt == K){
                s.insert(loc+1,1,'-');
                loc++;
                cnt = 0;
                continue;
            }
            if(s[loc] == '-'){
                s.erase(loc,1);
                continue;
            }
            cnt++;
        }
        if(s[0] == '-')
            s.erase(0,1);
        return s;
        //它更慢了？比第一种方法还要慢？？为什么啊，我只有一边头啊？
    }
    string licenseKeyFormatting3(string s, int K) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        int loc = 0;
        while(loc < s.length()){
            if(s[loc] == '-'){
                s.erase(loc,1);//去‘-’
                continue;
            }                
            loc++;
        }
        int size = s.length(); loc = size%K;
        while(loc < s.length()){
            if(loc == 0){
                loc+=K;
                continue;
            }
            s.insert(loc,1,'-');
            loc+=K+1;;
        }
        return s;
    }
    string licenseKeyFormatting4(string s, int K) {
		int len = s.size();
		int alen = len*2;//当K取1时若s中没有'-'取到最大长度2*len-1,另需一位'\0'
		//记录字母
		char* a = new char[alen+1];//为了方便,浪费一位
		a[alen] = '\0';
		//alen-j-cnt为数组a的当前索引,这里用从1开始增加方便计数取模
		int j = 1;//字母的计数
		int cnt = 0;//'-'号的计数
		//从后往前扫描
		for(int i=len-1;i>=0;i--){
			if(s[i]=='-')
				continue;
			if(s[i]<='z' && s[i]>='a')
				s[i] = s[i]-'a'+'A';
			a[alen-j-cnt] = s[i];
			//如K=3,j从1,2,3是一组,接下来就是新的一组了
			if(j%K==0){
				cnt++;
				a[alen-j-cnt] = '-';
			}
			j++;
		}
		//去除最前面的'-'号(至多有1个)
		return a[alen-j-cnt+1]!='-' ? string(a+alen-j-cnt+1) : string(a+alen-j-cnt+2);
        //快点了？
    }
    /*测试用例
    	"5F3Z-2e-9-w"
        4        
        "2-4A0r7-4k"
        3
        "2-5g-3-J"
        2
        "--a-a-a-a--"
        2
    */
};
```

