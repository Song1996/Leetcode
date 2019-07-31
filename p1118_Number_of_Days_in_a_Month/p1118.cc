class Solution {
public:
    int numberOfDays(int Y, int M) {
        if(M==2) {
            if(!(Y%4)) {
                if(!(Y%100)) {
                    if(!(Y%400)) {
                        return 29;
                    } else {
                        return 28;
                    }                       
                }else return 29;
            } else {
                return 28;
            }

        }
        if(M==1||M==3||M==5||M==7||M==8||M==10||M==12) return 31;
        if(M==4||M==6||M==9||M==11) return 30;
        return -1;
    }
};