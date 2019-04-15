#include<string>
#include<iostream>
#include<cstdlib>

using namespace std; 

/*
find longest path
for every point, it's actualy
N(left) + 1 + N(right)
(+1)
compare
return value
		  A
		 / \
 ---->	D  E
	   /\
	  E  F(1, 1)
	 / \
    G   T
         \
         M
         4, 3
*/

struct TreeNode
{
	int val; 
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//N(left)_max + 1 + N(right)_max (then we also need to compare)
// my goal is to have the final biggest path, but what I really need from two branches are 
int cal_longest(TreeNode* root, int& length)
{
	if(root==NULL)
	{
		length = 0;
		return 0;
	} 
	int len_left(0), len_right(0);
	int left_max = cal_longest(root->left, len_left);
	int right_max = cal_longest(root->right, len_right);
	// left_max + right_max + 1 is my path length
	length = max<int>( max<int>( left_max + 1 + right_max, len_left), right_max);

	return max<int>(left_max, right_max);
}

int main()
{
	TreeNode root(1);
	TreeNode* node1 = new TreeNode(2);
	// TreeNode node2;
	// TreeNode* node1(1);
	// TreeNode* node2(1);
	// TreeNode* node3(1);
	// TreeNode* node4(1);
	// root->left = node1;
	// root->right = node2;
	// root->left->left = node3;
	// root->left->right = node4;
	cout<<"this code for tree path search"<<endl;
	return 0;
}
