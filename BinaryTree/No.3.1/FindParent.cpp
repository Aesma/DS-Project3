#include "FindParent.h"

FindParent::FindParent()
{
	nullNode = '#';
}

bool FindParent::doFind(QString str, char child)
{
	BinaryTree<char> tree(nullNode);
	char *ch = new char[str.length()];
	string stdStr = str.toStdString();
	ch = (char*)stdStr.c_str();
	tree.CreatBinTree(ch);
	tree.Find(child);
	tree.getParent(parent);
	treeHeight = tree.Height();
	tree.getRoot(r);

	return true;
}

bool FindParent::doLevelFind(QString str, char child)
{
	BinaryTree<char> tree(nullNode);
	char *ch = new char[str.length()];
	string stdStr = str.toStdString();
	ch = (char*)stdStr.c_str();
	tree.CreatLevelBinTree(ch);
	tree.Find(child);
	tree.getParent(parent);
	treeHeight = tree.Height();
	tree.getRoot(r);

	return true;
}

bool FindParent::getParent(QVector<BinTreeNode<char>>&p)
{
	p = parent;

	return true;
}

bool FindParent::doSwap(QString &str)
{
	BinaryTree<char> tree(nullNode);
	char *ch = new char[str.length()];
	std::string stdStr = str.toStdString();
	ch = (char*)stdStr.c_str();
	tree.CreatBinTree(ch);
	tree.swapTree();
	tree.preOrder();
	str = tree.getNewTree();
	treeHeight = tree.Height();
	tree.getRoot(r);

	return true;
}

bool FindParent::doLevelSwap(QString &str)
{
	BinaryTree<char> tree(nullNode);
	char *ch = new char[str.length()];
	std::string stdStr = str.toStdString();
	ch = (char*)stdStr.c_str();
	tree.CreatLevelBinTree(ch);
	tree.swapTree();
	str = tree.getLevelStr();
	treeHeight = tree.Height();
	tree.getRoot(r);

	return true;
}

BinTreeNode<char>* FindParent::getRoot()
{
	return r;
}

int FindParent::Height()
{
	return treeHeight;
}

FindParent::~FindParent()
{

}