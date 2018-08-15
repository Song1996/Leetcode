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
        root = find(root);
        while(root!=NULL && (root->left!=NULL||root->right!=NULL)) {
            TreeLinkNode* p = root;
            while(p!=NULL) {
                TreeLinkNode* t = find(p->next);
                if(p->left!=NULL && p->right!=NULL) {
                    p->left->next = p->right;
                    if(t==NULL) p->right->next = NULL;
                    else if(t->left!=NULL) p->right->next = t->left;
                    else if(t->right!=NULL) p->right->next = t->right;
                    else assert(0);
                }else if(p->left!=NULL && p->right==NULL) {
                    if(t==NULL) p->left->next = NULL;
                    else if(t->left!=NULL) p->left->next = t->left;
                    else if(t->right!=NULL) p->left->next = t->right;
                    else assert(0);
                }else if(p->left==NULL && p->right!=NULL) {
                    if(t==NULL) p->right->next = NULL;
                    else if(t->left!=NULL) p->right->next = t->left;
                    else if(t->right!=NULL) p->right->next = t->right;
                    else assert(0);
                }
                p = t;
            }
            if(root->left!=NULL) root = find(root->left);
            else root = find(root->right);
        }
        return;
    }
    TreeLinkNode* find(TreeLinkNode* p) {
        if(p==NULL) return p;
        while(p!=NULL) {
            if(p->left!=NULL) return p;
            if(p->right!=NULL) return p;
            p = p->next;
        }
        return p;
    }
};

int main () {
	return 0;
}