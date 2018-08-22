#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    TreeNode* ans;
    TreeNode* r;
    BSTIterator(TreeNode *root) {
        r = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(r==NULL) return false;
        if(r->left==NULL) {
            ans = r;
            r = r->right;
            return true;
        }
        TreeNode* par = r;
        ans = par->left;
        while(ans->left!=NULL) {
            par = ans;
            ans = ans->left;
        }
        par->left = ans->right;
        return true;
    }
    /** @return the next smallest number */
    int next() {
        return ans->val;
    }
};

int main () {
	return 0;
}