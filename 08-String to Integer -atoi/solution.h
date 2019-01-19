class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        int i=0;bool b=true,a=true,c = false;
        while(i<str.size())
        {
            
            if(str[i]==' ') 
            {
                ++i;
                continue;
            }
            if(str[i] == '-') 
            {
                indicator = -1;
                a=false;
                ++i;
            }
            if(str[i] == '+' && a) 
            {
                b = false;
                ++i;
            }
            while(i<str.size())
            { c = true;
                if(str[i]>='0' && str[i]<='9')
                {
                   
                    result = result*10 + str[i]-'0';
                    if(result*indicator < -2147483648 ) return -2147483648;
                    if(result*indicator > 2147483647 ) return 2147483647;
                }
                else
                    break;
                    
                ++i;
            }
                
            if(!a || !b || c) break;
        }
       if(c) return result*indicator;
                    else return 0;
    }
};
