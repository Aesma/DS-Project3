#include "MakeTree.h"

bool MakeTree::ensureTree(BinTreeNode<char>*&subTree, QString preTree, QString inorderTree)
{
	if (inorderTree == "" || count == preTree.length()){
		subTree = new BinTreeNode<char>('#');
		subTree->leftChild = NULL;
		subTree->rightChild = NULL;
		return false;
	}
	string tempPre, tempIn;
	char *pre = new char[preTree.length()];
	char *inorder = new char[inorderTree.length()];
	tempPre = preTree.toStdString();
	tempIn = inorderTree.toStdString();
	pre = (char*)tempPre.c_str();
	inorder = (char*)tempIn.c_str();
	QString leftIn, rightIn;
	subTree = new BinTreeNode<char>(pre[count]);
	for (int i = 0; i < inorderTree.length(); i++)
	{
		if (inorder[i] == pre[count]){
			count++;
			leftIn = inorderTree.left(i);
			rightIn = inorderTree.right(inorderTree.length() - i - 1);
			break;
		}
	}
	ensureTree(subTree->leftChild, preTree, leftIn);
	ensureTree(subTree->rightChild, preTree, rightIn);
	
	return true;
}

void MakeTree::getRoot(BinTreeNode<char>*&r)
{
	r = Copy(root);
}

QString MakeTree::getLevelStr()
{
	QString newTreeStr = "已确定树的层次序列:";
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

int MakeTree::getHeight()
{
	return Height(root);
}