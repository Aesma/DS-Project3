#ifndef FINDPARENT_H
#define FINDPARENT_H

#include "BinaryTree.h"

#include <QVector>
#include <QtGui>

class FindParent
{
public:
	FindParent();
	bool doFind(QString str, char child);
	bool getParent(QVector<BinTreeNode<char>>&p);
	bool doSwap(QString &str);
	bool doLevelFind(QString str, char child);
	bool doLevelSwap(QString &str);
	BinTreeNode<char>* getRoot();
	int Height();
	~FindParent();
private:
	char nullNode;
	int treeHeight;
	QVector<BinTreeNode<char>>parent;
	BinTreeNode<char>*r;
};

#endif