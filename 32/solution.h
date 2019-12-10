class Solution {
public:
    int longestValidParentheses(string s) {
        //处理特殊情况
        if(s.length()<2) return 0;

        //处理不合理开头和结尾
        int i = 0,length = s.length();
        bool t = false;
        while(i<length && s[i] == ')') {
           i++; 
           t = true;
        } 
        if(t){
           s = s.substr(i); 
           t = false;
        } 
        i = s.length();
        while(i>1 && s[i-1] == '(') {
           i--; 
           t = true;
        }
        if(t) s = s.substr(0,i);

        vector<int> vtemp;
        int re = 0, valid = 0, start = 0;length = s.length();
        i = 0;//正向收集合理段
        for(; i < length; i++){
            if(s[i] == '(') valid++;
            if(s[i] == ')') valid--;
            if(valid == 0 ) {
                vtemp.push_back(start);
                vtemp.push_back(i);
                start = i+1;
            }
            if(valid < 0) {
               start = i+1; 
               valid = 0;
            }
        }
        
        for(int j = 0; j < vtemp.size(); j+=2){
           // return vtemp[3];
            int tmp = vtemp[j+1]-vtemp[j] + 1;
            for(j+=2 ; j < vtemp.size(); j+=2 ){
                if(vtemp[j-1] == vtemp[j] -1){
                    tmp += vtemp[j+1]-vtemp[j]+1;  
                }else{
                    j-=2;
                    break;
                }
            }
            re = (re > tmp)? re : tmp;
        }



        if(start < length && valid > 0){
            vtemp.clear();
            valid = 0; int end = length-1;
            for(i = length -1 ; i > start ; i--){
                if(s[i] == '(') valid--;
                if(s[i] == ')') valid++;
                if(valid == 0){                
                    vtemp.push_back(end);
                    vtemp.push_back(i);
                    end = i-1;
                }
                if(valid < 0) {
                  end = i-1;  
                  valid = 0;
                }
            }
            for(int j = 0; j < vtemp.size(); j+=2){
                //return vtemp[5];
                int tmp = vtemp[j]-vtemp[j+1]+1;
                for(j+=2 ; j< vtemp.size(); j += 2){
                    if(vtemp[j-1] == vtemp[j]+1){
                        tmp += vtemp[j]-vtemp[j+1]+1;
                    }else{
                        j-=2;
                        break;
                    }
                }
                re = (re > tmp)? re : tmp;
            }
        }
        return re;
    }
};