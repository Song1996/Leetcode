#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for(int i = 0; i < address.length(); i++) {
            if(address[i] == '.') {
                return address.substr(0,i) + string("[.]") + defangIPaddr(address.substr(i+1));
            }
        }
        return address;
    }
};
