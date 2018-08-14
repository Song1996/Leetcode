#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* ans = head;
        if(((ans->next)->val)!=(ans->val)) ans->next = deleteDuplicates(ans->next);
        else {
            while( (head->next)!=NULL && head->next->val == head->val) {
                head = head->next;
            }
            ans = deleteDuplicates(head->next);
        }
        
    }
};

int main () {
	return 0;
}