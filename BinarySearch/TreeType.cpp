#include "stdafx.h"
#include "TreeType.h"






TreeType::TreeType()
{
}


TreeType::~TreeType()
{
}








TreeNode * TreeType::GetPredecessor(TreeNode * tree)
{
	while (tree->right != NULL) {
		tree = tree->right;
	}


	return tree;
}

void TreeType::Delete(TreeNode *& tree, Contact details)
{
	TreeNode* tmpPtr = tree;
	if (tree == NULL) {
		cout << "Noting to delete!" << endl;
	}
	else if (details.surName < tree->info.surName) {
		cout << "Phone: " << details.phoneNumber << endl;
		Delete(tree->left, details);
	}
	else if (details.surName > tree->info.surName) {
		cout << "Phone: " << details.phoneNumber << endl;
		Delete(tree->right, details);
	}
	else {
		//Check if left and right is empty, if so then delete parent
		if (tree->left == NULL && tree->right == NULL) {
			delete tree;
			tree = NULL;
		}
		//Check if left is empty then delete parent
		else if (tree->left == NULL) {
			tmpPtr = tree;
			tree = tree->right;
			delete tmpPtr;
			tree = NULL;
		}
		//Check if right is empty then delete parent
		else if (tree->right == NULL) {
			tmpPtr = tree;
			tree = tree->left;
			delete tmpPtr;
			tree = NULL;
		}
		else {
			tmpPtr = GetPredecessor(tree->left);
			tree->info = tmpPtr->info;
			Delete(tree->right, details);
		}
	}
}

void TreeType::FindPhone(Contact temp)
{
	SearchPhone(root, temp);
}

void TreeType::SearchPhone(TreeNode * tree, Contact temp)
{
	
	if (tree != NULL) {
		//cout << "Debug inside if" << endl;

		if (tree->left != NULL) {
			SearchPhone(tree->left, temp);
		}

		if (temp.phoneNumber == tree->info.phoneNumber) {
			cout << "\n\nPhone number found!" << endl;
			cout << "Phone: " << tree->info.phoneNumber << "\n\n" << endl;
			Delete(root, temp);
		}

		if (tree->right != NULL) {
			SearchPhone(tree->right, temp);
		}
	}
	else {
		cout << "\n\n***Tree is empty!***" << endl;
	}
}

void TreeType::SearchFirstChar(Contact temp)
{
	SearchFirstLetterSurname(root, temp);
}

void TreeType::SearchFirstLetterSurname(TreeNode* tree, Contact& temp)
{
	if (tree != NULL) {
		if (tree->info.surName[0] == temp.surName[0]) {
			cout << "\n\n********************************" << endl;
			cout << "* " << tree->info.firstName << " " << tree->info.surName << " " << tree->info.phoneNumber << "\t\t*" << endl;
			cout << "********************************" << endl;
		}
		else {
			if (temp.surName[0] < tree->info.surName[0]) {
				SearchFirstLetterSurname(tree->left, temp);
			}
			else {
				SearchFirstLetterSurname(tree->right, temp);
			}
		}
	}
	else {
		cout << "Tree is empty!" << endl;
	}
}






void TreeType::Retrieve(TreeNode* tree, Contact& temp)
{
	if (tree != NULL) {

		if (tree->left != NULL) {
			Retrieve(tree->left, temp);
		}

		if (temp.surName == tree->info.surName) {
			cout << "\n\n********************************" << endl;
			cout << "* " << tree->info.firstName << " " << tree->info.surName << " " << tree->info.phoneNumber << "\t\t*" << endl;
			cout << "********************************" << endl;
		}

		if (tree->right != NULL) {
			Retrieve(tree->right, temp);
		}
	}
	else {
		cout << "Tree is empty!" << endl;
	}
}


void TreeType::RetrieveItem(Contact temp)
{
	Retrieve(root, temp);
}



void TreeType::Destroy(TreeNode*& temp)
{
	if (temp != NULL) {
		Destroy(temp->left);
		Destroy(temp->right);
		delete temp;
	}
}





void TreeType::Insert(TreeNode*& tree, Contact p)
{
	//TreeNode* node = new TreeNode;
	//node->info = p;

	if (tree == NULL)
	{			// Insertion place found.
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = p;
	}
	else if (p.surName < tree->info.surName) {
		Insert(tree->left, p);
	}
		     					// Insert in left subtree.
	else {
		Insert(tree->right, p);
	}
		    					// Insert in right subtree.
														// Insert in right subtree.


}

void TreeType::InsertItem(Contact temp)
{
	Insert(root, temp);
}

void TreeType::DeleteTree()
{
	Destroy(root);
	root = NULL;
}

void TreeType::ResetTree()
{
	Destroy(root);
	root = NULL;
}



void TreeType::Display()
{
	DisplayTree(root);
}

void TreeType::DisplayTree(TreeNode*& temp)
{
	
 	if (root == NULL) {
		cout << "Tree is empty";
	}
	else {
		if (temp->left != NULL) {
			DisplayTree(temp->left);
		}
		cout << "* [Firstname: " << temp->info.firstName << " ] [Surname: " << temp->info.surName << " ] [Phone Numebr:] " << temp->info.phoneNumber << "]\t\t*" << endl;
		if (temp->right != NULL) {
			DisplayTree(temp->right);
		}
		
	}
}
