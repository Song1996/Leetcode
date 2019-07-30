#include <cstring>
using namespace std;

class Solution {
    int mem[10];
public:
    bool isArmstrong(int N) {
        memset(mem, 0, sizeof(mem));
        int k = 0, tN = N;
        while(tN) {
            k++;
            tN /= 10;
        }
        int t = 0;
        tN = N;
        while(tN) {
            int digit = tN%10;
            if(digit!=0 && mem[digit] == 0) {
                mem[digit] = 1;
                for(int i = 0; i < k; i++) {
                    mem[digit] *= digit;
                }
            }
            if(t > N - mem[digit]) return false;
            t += mem[digit];
            tN /= 10;
        }
        return t == N;
    }
};