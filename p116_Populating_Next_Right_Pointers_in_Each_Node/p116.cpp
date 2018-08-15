#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        root->next = NULL;
        while(root->left!=NULL) {
            TreeLinkNode* p = root;
            while(p!=NULL) {
                p->left->next = p->right;
                if(p->next==NULL) p->right->next = NULL;
                else p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }
        return;
    }
};

int main () {
	return 0;
}