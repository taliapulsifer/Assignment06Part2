#include "btNode.h"

// write definition for bst_insert here
void bst_insert(btNode*& bst_root, int newNode)
{
	if (bst_root == 0)
	{
		//empty tree
		btNode* newRoot = new btNode;
		newRoot->data = newNode;
		newRoot->left = newRoot->right = 0;
		bst_root = newRoot;
		return;
	}
	//Create cursor for tree traversal

	btNode* cursor = new btNode;

	while (cursor != 0)
	{

		if (cursor->data > newNode)
		{
			//If current node is greater than target data
			// then insert on the left side

			if (cursor->left == 0)
			{
				//Empty spot for new node found!
				cursor->left = new btNode;
				cursor->left->data = newNode;
				cursor->left->left = cursor->right->right = 0;
				return;
			}
			else {//No empty spot found
				cursor = cursor->left;
			}

		}
		else if (cursor->data < newNode)
		{
			//If the cursor data is less than the target data
			// then insert on the right side

			if (cursor->data == 0)
			{
				//Empty spot for new node found
				cursor->right = new btNode;
				cursor->right->data = newNode;
				cursor->right->left = cursor->right->right = 0;
				return;
			}
			else
			{//Keep searching
				cursor = cursor->right;
			}

		}
		else
		{
			//Parent node matches the target data. Do not 
			//do anything

			return;
		}
		
	}

}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int target)
{
	if (bst_root == 0) { return false; }

	if (bst_root->data > target)
	{
		//Targer is less than root
		bst_remove(bst_root->left, target);
	}
	else if (bst_root->data < target)
	{
		//Target is greater than root
		bst_remove(bst_root->right, target);
	}
	else
	{
		//Target is equal to the root

		if (bst_root->left != 0 && bst_root != 0)
		{
			bst_remove_max(bst_root->left, bst_root->data);
		}
		else
		{
			btNode* oldBSTRoot = bst_root;

			if (bst_root->left == 0 && bst_root->right != 0)
			{
				bst_root = bst_root->right;
			}
			else if (bst_root->left != 0 && bst_root->right == 0)
			{
				bst_root = bst_root->left;
			}
			else 
			{
				bst_root = 0;
			}
			
			delete oldBSTRoot;
		}
		return true;

	}
}

// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int& data)
{
	if (bst_root == 0) { return;}
	if (bst_root->right == 0)
	{
		btNode* nodeToDelete = bst_root;
		data = bst_root->data;
		bst_root = bst_root->left;
		delete nodeToDelete;
	}
	else
	{
		bst_remove_max(bst_root->right, data);
	}
}

void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
