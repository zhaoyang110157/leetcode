
class Solution {
public:
   int reverse(int x){
       bool flag=true;
       if(x<0)
       {
           x=-x;
           flag=false;
       }
       long re=0;
       while(x>0)
       {
           re=re*10+x%10;
           x/=10;
           if(re>INT_MAX ||re<INT_MIN)
            return 0;
       }
       if(!flag) re=-re;
       return re;
   }
};
