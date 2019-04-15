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
#include <algorithm>
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
    if(preorder.size()==1 && inorder.size()==1)
    {
      TreeNode* Node = new TreeNode(preorder[0]);
      return Node;
    }
    TreeNode* Node = new TreeNode(preorder[0]);
    auto it=find(inorder.begin(), inorder.end(), preorder[0]);
    int index= distance(inorder.begin(), it);
    // something like below
    vector<int> left_pre(preorder.begin()+1, preorder.begin()+index);
    vector<int> left_in(inorder.begin(), inorder.begin()+index);
    vector<int> right_pre(preorder.begin()+index+1, preorder.end());
    vector<int> right_in(inorder.begin()+index+1, inorder.end());
    Node->left = buildTree(left_pre, left_in);
    Node->right= buildTree(right_pre, right_in);
    return Node;
};

TreeNode* buildTreeInR(vector<int>& inorder, vector<int>& postorder)
{
    if(preorder.size()==0 || inorder.size()==0)
    {
      return NULL;
    }
    if(preorder.size()==1 && inorder.size()==1)
    {
      TreeNode* Node = new TreeNode(preorder[0]);
      return Node;
    }
    TreeNode* Node = new TreeNode(preorder[0]);
    auto it=find(inorder.begin(), inorder.end(), preorder[0]);
    int index= distance(inorder.begin(), it);
    // something like below
    vector<int> left_pre(preorder.begin()+1, preorder.begin()+index);
    vector<int> left_in(inorder.begin(), inorder.begin()+index);
    vector<int> right_pre(preorder.begin()+index+1, preorder.end());
    vector<int> right_in(inorder.begin()+index+1, inorder.end());
    Node->left = buildTree(left_pre, left_in);
    Node->right= buildTree(right_pre, right_in);
    return Node;
};


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
  vector<int> postorder{};
  auto it=find(preorder.begin(), preorder.end(), 8);
  int index = distance(preorder.begin(), it);
  cout<<"element 8 has index: "<<index<<endl;
  vector<int> a(preorder.begin(), preorder.begin()+2);
  TreeNode* root;
  root = buildTree(preorder, inorder);
  cout<<root->left->val<<endl;
  return 0;
}
