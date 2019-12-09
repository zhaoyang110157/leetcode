class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        return haystack.find(needle);
    }
};
class Solution 1{
public:
    int strStr(string haystack, string needle) {
        // 特殊情况判断
        if(haystack.length() < needle.length()) return -1;
        if(needle.length() == 0) return 0;
        
        // 双指针，i指向haystack，j指向needle
        int i = 0, j = 0;
        while(i < haystack.length()) {
            // 判断当前两个字符是否相等
            if(haystack[i] == needle[j]) {
                // 相等，则i，j自增1，若此时j越界，则找到索引
                j++;
                i++;
                if(j >= needle.length())
                    return i - j;
            }
            else {
                // 不相等，判断j是否越界
                if(j < needle.length()) {
                    //未越界，则i重置为haystack中与needle的第一个字符相等的第一个字符位置的后一位，j重置为0
                    i = i - j + 1;
                    j = 0;
                }
                else {
                    // 越界，i自增1
                    i++;
                }
            }
        }
        return -1;
    }
};