#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int l = str.length();
        int i = 0;
        int result = 0;
        bool nflag = false;
        bool meetflag = false;
        while(i < l && str[i]==' '){
            i ++;
        }
        if(str[i] == '+') ;
        else if (str[i] == '-') nflag = true;
        else if (int(str[i]) <= int('9') && int(str[i]) >= int('0')) 
            result += int(str[i]) - int('0');
        else return 0;
        i ++;
        int digit_value = 0;
        while(int(str[i])<=int('9') && int(str[i])>=int('0') && i < l) { 
            digit_value = int(str[i])-int('0');
            if (nflag && result < (INT_MIN + digit_value)/10 )
                return INT_MIN;
            else if (!nflag && result > (INT_MAX - digit_value)/10)
                return INT_MAX;
            result *= 10;
            result += nflag?-1*(int(str[i]) - int('0')):(int(str[i]) - int('0'));
            i ++;
        }
        return result;
    }
};

int main () {
    string x;
    int y;
    Solution s;
    x = "42";
    y = 42;
    printf("%d, %d\n",y,s.myAtoi(x));
    x = "   -42";
    y = -42;
    printf("%d, %d\n",y,s.myAtoi(x));
    x = "4193 with words";
    y = 4193;
    printf("%d, %d\n",y,s.myAtoi(x));
    x = "words and 987";
    y = 0;
    printf("%d, %d\n",y,s.myAtoi(x)); 
    x = "-91283472332";
    y = -2147483648;
    printf("%d, %d\n",y,s.myAtoi(x));  
    x = "-2147483648";
    y = -2147483648;
    printf("%d, %d\n",y,s.myAtoi(x));    
    x = "2147483647";
    y = 2147483647;
    printf("%d, %d\n",y,s.myAtoi(x));    
    x = "2147483648";
    y = 2147483647;
    printf("%d, %d\n",y,s.myAtoi(x));  
    x = "-2147483649";
    y = -2147483648;
    printf("%d, %d\n",y,s.myAtoi(x));   
}