#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "SeqQueue.h"
#include <cstdlib>
#include <QVector>
#include <iostream>
using namespace std;

template <class T>
struct BinTreeNode
{
	T data;
	int h;
	int w;
	int n;
	BinTreeNode<T>*leftChild, *rightChild;
	BinTreeNode() :data(35), leftChild(NULL), rightChild(NULL), h(0), w(0), n(0){};
	BinTreeNode(T x, BinTreeNode<T>*l = NULL, BinTreeNode<T>*r = NULL)
		:data(x), leftChild(l), rightChild(r), h(0), w(0), n(0){};
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() :root(NULL), count(0), newTreeStr(""){};
	BinaryTree(T value) :RefValue(value), root(NULL), count(0), newTreeStr(""){};
	BinaryTree(BinaryTree <T>&s);//复制构造函数
	bool IsEmpty(){ return (root == NULL) ? true : false; };
	void CreatBinTree(T item, BinTreeNode<T>*&subTree);
	int Height(){ return Height(root); };
	BinTreeNode<T>*Parent(BinTreeNode<T>*current)//返回父节点
	{
		return (root == NULL || root == current) ? NULL : Parent(root, current);
	}
	void getRoot(BinTreeNode<T>*&tempRoot);
	void CreatBinTree(T *Data)
	{
		count = 0;
		CreatBinTree(Data, root);
	}
	void CreatLevelBinTree(T *Data)
	{
		count = 0;
		CreatLevelBinTree(Data, root);
	}
	void swapTree()
	{
		swapTree(root);
	}
	int Insert(const T& item);
	BinTreeNode<T> *Find(T &item)
	{
		return Find(root, item);
	}
	void getParent(QVector<BinTreeNode<T>>&p);
	QString getNewTree(){ return newTreeStr; };
	QString getLevelStr();
	void preOrder(){ preOrder(root); };
	~BinaryTree(){ destroy(root); };
protected:
	BinTreeNode<T> *root;
	T RefValue;
	void CreatBinTree(T *Data, BinTreeNode<T>*&subTree);
	void CreatLevelBinTree(T *Data, BinTreeNode<T>*&subTree);
	void destroy(BinTreeNode<T>*&subTree);	
	BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);
	BinTreeNode<T>*Parent(BinTreeNode<T>*subTree, BinTreeNode<T> *current);
	BinTreeNode<T>*Find(BinTreeNode<T>*subTree, const T&x); //搜寻x
	void preOrder(BinTreeNode<T>*subtree);
	void swapTree(BinTreeNode<T>*&subTree);
	int Height(BinTreeNode<T>*subTree);
private:
	QVector<BinTreeNode<T>>parent;
	QString newTreeStr;
	int count;
};

template <class T>
void BinaryTree<T>::CreatBinTree(T *Data, BinTreeNode<T>*& subTree)
{
	T item;
	if (count < strlen(Data)){
		item = Data[count++];
		if (item != RefValue){
			subTree = new BinTreeNode<T>(item);
			if (subTree == NULL){
				cerr << "分配错" << endl;
				exit(1);
			}
			CreatBinTree(Data, subTree->leftChild);
			CreatBinTree(Data, subTree->rightChild);
		}
		else
			subTree = NULL;
	}
}

template <class T>
void BinaryTree<T>::CreatLevelBinTree(T *Data, BinTreeNode<T>*& subTree)
{
	SeqQueue<BinTreeNode<T>*>Q;
	T item;
	item = Data[count++];
	if (item != RefValue){
		subTree = new BinTreeNode<T>(item);
		subTree->leftChild = new BinTreeNode<T>;
		subTree->rightChild = new BinTreeNode<T>;
		Q.EnQueue(subTree->leftChild);
		Q.EnQueue(subTree->rightChild);
		if (subTree == NULL){
			return;
		}
	}
	else{
		subTree = NULL;
		return;
	}
	BinTreeNode<T>*tempNode = subTree;
	while (!Q.IsEmpty())
	{
		if (count == strlen(Data))
			break;
		item = Data[count++];
		Q.DeQueue(subTree);
		if (item != RefValue){
			subTree->data = item;
			subTree->leftChild = new BinTreeNode<T>;
			subTree->rightChild = new BinTreeNode<T>;
			Q.EnQueue(subTree->leftChild);
			Q.EnQueue(subTree->rightChild);
			if (subTree == NULL){
				return;
			}
		}
		else{
			subTree = NULL;
		}
	}
	subTree = tempNode;
}

template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *&subTree)
{
	if (subTree != NULL){
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}

template <class T>
QString BinaryTree<T>::getLevelStr()
{
	SeqQueue<BinTreeNode<char>*>Q;
	BinTreeNode<char>*p = root;
	Q.EnQueue(p);
	while (!Q.IsEmpty())
	{
		Q.DeQueue(p);
		newTreeStr += p->data;
		if (p->leftChild != NULL)
			Q.EnQueue(p->leftChild);
		if (p->rightChild != NULL)
			Q.EnQueue(p->rightChild);
	}

	return newTreeStr;
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current)
{
	if (subTree == NULL)
		return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;
	BinTreeNode<T>*p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)
		return p;
	else
		return Parent(subTree->leftChild, current);
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T>*orignode)
{
	if (orignode == NULL){
		return NULL;
	}
	BinTreeNode<T>*temp = new BinTreeNode<T>;
	temp->data = orignode->data;
	temp->leftChild = Copy(orignode->leftChild);
	temp->rightChild = Copy(orignode->rightChild);
	return temp;
}

template <class T>
void BinaryTree<T>::getRoot(BinTreeNode<T>*&tempRoot)
{
	tempRoot = Copy(root);
}

template <class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>*subTree)
{
	if (subTree != NULL)
	{
		newTreeStr += subTree->data;
		preOrder(subTree->leftChild);
		preOrder(subTree->rightChild);
	}
	else{
		newTreeStr += "#";
	}
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Find(BinTreeNode<T>*subTree, const T&x)
{
	if (subTree == NULL){
		return NULL;
	}
	if (subTree->data == x){
		parent.push_back(*subTree);
		return subTree;
	}
	BinTreeNode<T>*p;
	p = Find(subTree->leftChild, x);
	BinTreeNode<T>*q;
	q = Find(subTree->rightChild, x);
	if (p != NULL){
		parent.push_back(*subTree);
		return p;
	}
	else if (q != NULL){
		parent.push_back(*subTree);
		return q;
	}
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& s)
{
	root = Copy(s.root);
}

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T>*subTree)
{
	if (subTree == NULL)
		return 0;
	else{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

template <class T>
void BinaryTree<T>::swapTree(BinTreeNode<T>*&subTree)
{
	if (subTree != NULL){
		BinTreeNode<T>* temp = subTree->leftChild;
		subTree->leftChild = subTree->rightChild;
		subTree->rightChild = temp;
		swapTree(subTree->leftChild);
		swapTree(subTree->rightChild);
	}
}

template <class T>
void BinaryTree<T>::getParent(QVector<BinTreeNode<T>>&p)
{
	p = parent;
}

template <class T>
int operator ==(const BinaryTree<T>&s, const BinaryTree<T>&t)
{
	return (equal(s.root, t.root)) ? true : false;
}

template <class T>
bool equal(BinTreeNode<T>*a, BinTreeNode<T>*b)
{
	if (a == NULL&&b == NULL)
		return true;
	if (a != NULL&&b != NULL&&a->data == b->data&&equal(b->leftChild, a->leftChild) && equal(a->rightChild, b->rightChild))
		return true;
	else
		return false;
};

#endif