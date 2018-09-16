#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> S(G.begin(), G.end());
        bool flag = false;
        int ans = 0;
        while(head) {
            auto p = S.find(head->val);
            if(p!=S.end()) {
                if(!flag) {
                    flag = true;
                    ans++;
                }
            }else if(flag) flag = false;
            head = head->next;
        }
        return ans;
    }
};

int main() {
    return 0;
}