#pragma once
#include <string>
using namespace std;

struct Contact {
	string firstName;
	string surName;
	int phoneNumber;
};

struct TreeNode
{
	Contact info;
	TreeNode* left;
	TreeNode* right;
};



class TreeType
{
public:
	TreeType();
	~TreeType();

	
	void DeleteNode(Contact temp);
	TreeNode* GetPredecessor(TreeNode* tree);
	void Delete(TreeNode*& tree, Contact details);

	void FindPhone(Contact temp);
	void SearchPhone(TreeNode* tree, Contact temp);

	void SearchFirstChar(Contact temp);
	void SearchFirstLetterSurname(TreeNode* tree, Contact& temp);

	void Retrieve(TreeNode* tree, Contact& temp);
	void RetrieveItem(Contact temp);

	void Insert(TreeNode*& tree, Contact p);
	void InsertItem(Contact info);

	void Destroy(TreeNode*& temp);
	void DeleteTree();
	void ResetTree();

	void Display();
	void DisplayTree(TreeNode*& temp);

private:
	TreeNode * root;
};

