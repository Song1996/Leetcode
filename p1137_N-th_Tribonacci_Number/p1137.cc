#include<cstring>
#include<cstdio>

class Solution {
public:
    /*
    x_ = M * x;
    M = [[1,1,1],[1,0,0],[0,1,0]];
    x0 = [0,1,1];
    xn = [Tn, Tn+1, Tn+2];
    [Tn-2, Tn-1, Tn] = M^(n-2) * x0;
    M^2 = M * M;
    */
    class vector3 {
    public:
        int elements[3];
        vector3() {
            memset(elements, 0, sizeof(elements));
        }
        vector3(const int *initElements) {
            memcpy(elements, initElements, sizeof(elements));
        }
        void operator += (const vector3& v) {
            for(int i = 0; i < 3; i++) {
                elements[i] += v.elements[i];
            }
        }
        void print(){
            printf("%d %d %d\n", elements[0], elements[1], elements[2]);
        }
    };
    constexpr static int aM[9] = {1,1,1,1,0,0,0,1,0};
    constexpr static int aV[3] = {1,1,0};
    class Matrix3x3 {
    public:
        int elements[3][3];
        Matrix3x3() {
            memset(elements, 0, sizeof(elements));
        }
        Matrix3x3(const int *initElements) {
            memcpy(elements, initElements, sizeof(elements));
        }
        Matrix3x3 operator * (const Matrix3x3& M) {
            Matrix3x3 ans;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++) {
                        ans.elements[i][j] += elements[i][k] * M.elements[k][j];
                    }
                }
            }
            return ans;
        }
        vector3 operator * (const vector3& v) {
            vector3 ans;
            for(int i = 0; i < 3; i++) {
                for(int k = 0; k < 3; k++) {
                    ans.elements[i] += elements[i][k] * v.elements[k];
                }
            }
            return ans;
        }
        void print() {
            printf("M:\n");
            for(int i = 0; i < 3; i++) {
                printf("%d %d %d\n", elements[i][0], elements[i][1], elements[i][2]);
            }
        }
    };
    Matrix3x3 M = Matrix3x3(aM);
    vector3 baseV = vector3(aV);
    
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        n -= 2;
        int a[9] = {1,0,0,0,1,0,0,0,1};
        Matrix3x3 baseM = Matrix3x3(a);
        while(n) {
            if(n&1) {
                baseM = M * baseM;
            }
            n >>= 1;
            if(n==0) break;
            M = M*M;
        }
        return (baseM*baseV).elements[0];
    }
};