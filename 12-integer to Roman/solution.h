class Solution {
public:
    string intToRoman(int num) {
        map<int,string> table;
        int level = 1;
        table[1] = "I";
        table[5] = "V";
        table[10] = "X";
        table[50] = "L";
        table[100] = "C";
        table[500] = "D";
        table[1000] = "M";
        stack<string> result;
        string str="";
        while(num>0)
        {
            int tmp = num%10;
            num /= 10;
            string now="";
            string a = table [ level*1 ];
            string b = table [ level*5 ];
            string c = table [ level*10 ];
            if(tmp>=5 && tmp < 9 )
            {
                now+=b;
                tmp %=5;
            }
            if(tmp < 4) 
               while(tmp--) now += a;
            if( tmp == 4 ) now += a+b;
            if( tmp == 9 ) now += a+c;
            level *= 10;
            result.push(now);
        }
        while(result.size())
        {
            str += result.top();
            result.pop();
        }
        return str;
    }
};

/*
solve the problem level by level
*/
