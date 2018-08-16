#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

int main () {
    vector<int> x;
    x.push_back(5); x.push_back(8); x.push_back(2);
    x.push_back(8); x.push_back(1); x.push_back(7);
    //x.erase(remove(x.begin(),x.end(),8),x.end());
    for(vector<int>::iterator it =remove(x.begin(),x.end(),8); it != x.end(); it++){
        printf("%d ",*it);
    }printf("\n");
    x.erase(remove(x.begin(),x.end(),8),x.end());
    for(int i = 0; i < x.size(); i++) printf("%d ",x[i]);
    printf("\n");
	return 0;
}