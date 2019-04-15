/*
C++ programming to implement hash tables
edit by Xiaolong Li
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

struct TreeNode
{
    int item;
    TreeNode *left;
    TreeNode *right;
};

class BinTree
{
private:
    TreeNode *tree;
public:
    // count methods
    BinTree(int root)
    {
        tree->item = root;
        tree->left = NULL;
        tree->right = NULL;
    }
    ~BinTree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();
};

int countNodes(TreeNode *root)
{
    if( root == NULL )
        return 0;
    else
    {
        int count = 1;
        count += countNodes(root->left);
        count += countNodes(root->right);
        return count;
    }
}

int main()
{
    BinTree tree(2);
    cout<<"tree's root is "<< countNodes(tree) <<endl;
    return 1;
}
