/*
94 102 144 145
Tree/graphs
2 ways, recursively or iteratively
in-order
pre-order
post-order
level-order
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode *> stack;
        stack.push(root);
        if(!root)
        {
            return answer;
        }
        while(!stack.empty())
        {
            TreeNode *newtree = stack.top();
            if(newtree->left)
            {
                stack.push(newtree->left);
                newtree->left = NULL;
            }
            else
            {
                answer.push_back(newtree->val);
                stack.pop();
                if(newtree->right)
                {
                    stack.push(newtree->right);
                }
            }
        }
        return answer;
    }
};
