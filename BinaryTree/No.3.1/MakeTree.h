#ifndef MAKETREE_H
#define MAKETREE_H

#include "BinaryTree.h"

class MakeTree:public BinaryTree<char>
{
public:
	MakeTree() :root(NULL), count(0){};
	bool ensureTree(QString preTree, QString inorderTree){ return ensureTree(root, preTree, inorderTree); };
	void getRoot(BinTreeNode<char>*&r);
	int getHeight();
	QString getLevelStr();
	~MakeTree(){ destroy(root); };
protected:
	bool ensureTree(BinTreeNode<char>*&subTree, QString preTree, QString inorderTree);
private:
	BinTreeNode<char>*root;
	int count;
};


#endif