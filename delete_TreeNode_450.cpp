/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* next = root;
        int left_flag = 0;
        while (next!=NULL)
        {
            TreeNode* prev = next;
            if next.val==key
            {
                if left_flag>0
                    prev.left = next.right;
                    
                else 
                    prev.right = next.right;
                return root;
            }
            else if next.val < key
            {
                next = next.right;
                left_flag = 0;
                
            }
            else
            {
                next = next.left;
                left_flag = 1;
            }

        }
        cout<<"no nodes available"<<endl;
        return;
    }
};
