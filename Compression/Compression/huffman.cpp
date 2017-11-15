#include "huffman.h"

HuffmanTree::HuffmanTree(info w[], int n)
{
	MinHeap<HuffmanNode>hp;
	HuffmanNode *parent, *first, *second, work;
	for (int i = 0; i < n; i++)
	{
		work.data = w[i];
		work.leftChild = NULL;
		work.rightChild = NULL;
		work.parent = NULL;
		hp.Insert(work);
	}
	for (int i = 0; i < n - 1; i++)
	{
		first = new HuffmanNode;
		second = new HuffmanNode;
		hp.RemoveMin(*first);
		hp.RemoveMin(*second);
		mergeTree(first, second, parent);
		hp.Insert(*parent);

		delete first;
		delete second;
	}
	root = copy(parent);
}

HuffmanTree::HuffmanTree(HuffmanTree &hf)
{
	root = copy(hf.root);
}

HuffmanNode* HuffmanTree::copy(HuffmanNode *orignode)
{
	if (orignode == NULL){
		return NULL;
	}
	HuffmanNode*huf_node = new HuffmanNode;
	huf_node->data = orignode->data;
	huf_node->leftChild = copy(orignode->leftChild);
	huf_node->rightChild = copy(orignode->rightChild);

	return huf_node;
}

HuffmanNode* HuffmanTree::getRoot()
{
	return copy(root);
}

void HuffmanTree::mergeTree(HuffmanNode*&bt1, HuffmanNode*&bt2, HuffmanNode*&parent)
{
	parent = new HuffmanNode;
	parent->leftChild = copy(bt1);
	parent->rightChild = copy(bt2);
	parent->data = bt1->data + bt2->data;
	bt1->parent = bt2->parent = parent;
}

void HuffmanTree::deleteTree(HuffmanNode*t)
{
	if (t != NULL){
		deleteTree(t->leftChild);
		deleteTree(t->rightChild);
		delete t;
	}
}