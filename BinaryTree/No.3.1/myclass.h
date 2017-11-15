#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QDialog>
#include <QMessageBox>
#include <cmath>

#include "ui_myclass.h"
#include "FindParent.h"
#include "MakeTree.h"

class MyClass : public QDialog,public Ui::MyClassClass
{
	Q_OBJECT
public:
	MyClass(QWidget *parent = 0);
	~MyClass();
protected:
	void paintEvent(QPaintEvent *event);
	void paintPreTree(BinTreeNode<char>*r);
public slots:
	bool doFind();
	bool doSwap();
	bool makeTree();
private:
	void dealDialog();
	void dealWcount(BinTreeNode<char>*&r);
	void dealHcount(BinTreeNode<char>*&r);
	void wcountPlus(BinTreeNode<char>*&r);
	void ensureTree(BinTreeNode<char>*&r, QString preTree, QString inorderTree);
private:
	QVector<BinTreeNode<char>>parent;
	BinTreeNode<char>*root;
	BinTreeNode<char>*node;
	FindParent find;
	MakeTree make;
	QString fTree;
	int h_tree;
	int h_count;
	int tempH;
	int tempW;
	int *w_count;
	bool isW;
	bool isPlus;
};

#endif // MYCLASS_H
