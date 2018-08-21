#include<functional>
#include<iostream>
#include<string>
using namespace std;

int main() {
    char c1[] = "hello world";
    char c2[] = "hello world";
    string s1 (c1);
    string s2 (c2);
    hash<char*> c_str_hash;
    hash<string> str_hash;
    printf("%lu %lu %lu %s\n",sizeof(str_hash(s1)), str_hash(s1),str_hash(s2), str_hash(s1)==str_hash(s2)?"true":"false");
    printf("%lu %lu %s\n", c_str_hash(c1),c_str_hash(c2), c_str_hash(c1)==c_str_hash(c2)?"true":"false");
    return 0;
}