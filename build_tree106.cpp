/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.size()==0 || inorder.size()==0)
    {
      return NULL;
    }
    if(predorder.size()==1 && inorder.size()==1)
    {
      TreeNode* Node = new TreeNode(preorder[0]);
      return Node;
    }
    TreeNode* Node = new TreeNode(preorder[0]);
    auto it=find(inorder.begin(), inorder.end(), preorder[0]);
    int index= distance(inorder.begin(), it);
    // something like below
    Node->left = buildTree(vector<int>(preorder.begin(),preorder.begin()+index), vector<int>(inorder.begin(),inorder.begin()+index));
    Node->right= buildTree(preorder[index+1:], inorder[index+1:]);
    return Node;
}


/**
          12
          / \
         7   16
        / \  / \
   L   5  8 15  20
**/

int main()
{
  cout<<"program for building tree from list "<<endl;
  vector<int> preorder{12, 7, 5, 8, 16, 15, 20};
  vector<int> inorder{5, 7, 8, 12, 15, 16, 20};
  TreeNode* root;
  root = buildTree(preorder, inorder);
  return 0;
}
