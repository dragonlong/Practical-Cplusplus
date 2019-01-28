#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class BST
{
private:
	struct node
	{
		int val;
		node* left;
		node* right;
	};
	node* root;
	void addLeafPriavte(int val, node* Ptr);
	void printInOrderPrivate(node* Ptr);
	void deleteNodePrivate(int val, node* parent);
	node* returnNodePrivate();
	int findSmallestPrivate(node *Ptr);
	void removeMatchRoot();
	void removeMatch(node* parent, node* match, bool left);

public:
	int index;
	BST();
	node* createLeaf(int val);
	void addLeaf(int val);
	void printInOrder();
	void deleteNode(int val);
	int findSmallest();//default from the root node

};

BST::BST()
{
	root = NULL;
	index = 2;

}

BST::node* BST::createLeaf(int val)
{
	node* n = new node;
	n->val = val;
	n->left = NULL;
	n->right= NULL;

	return n;
}

void BST::addLeafPriavte(int val, node* Ptr)
{
	if(root==NULL)
	{
		root = createLeaf(val);
	}
	else if(val<Ptr->val)
	{
		if(Ptr->left!=NULL)
		{
			addLeafPriavte(val, Ptr->left);
		}
		else
		{
			Ptr->left=createLeaf(val);
		}
	}
	else if(val>Ptr->val)
	{
		if(Ptr->right!=NULL)
		{
			addLeafPriavte(val, Ptr->right);
		}
		else
		{
			Ptr->right=createLeaf(val);
		}
	}
	else
	{
		cout<<"the val: "<<val<<" is already in our tree"<<endl;
	}
}

void BST::addLeaf(int val)
{
	addLeafPriavte(val, root);
}

void BST::printInOrder()
{
	printInOrderPrivate(root);
}

void BST::printInOrderPrivate(node* Ptr)
{
	if(root==NULL)
	{
		cout<<"This BST tree is empty"<<endl;
	}
	else
	{
		if(Ptr->left!=NULL)
		{
			printInOrderPrivate(Ptr->left);
		}
		cout<<Ptr->val<<" ";
		if(Ptr->right!=NULL)
		{
			printInOrderPrivate(Ptr->right);
		}
	}
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
	int a[]={50, 76, 21, 4, 32, 64, 15, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80, 0};
	vector<int> b(20, 1);
	// declare a class
	BST c;
	// call function using .  (pointers call members using ->
	int i=0;
	while(a[i]!=0)
	{
		c.addLeaf(a[i]);
		i++;
	}
	cout<<c.index<<endl;
	c.printInOrder();
	b.push_back(5);
	cout<<endl<<b.front()<<endl;
	return 0;
}
