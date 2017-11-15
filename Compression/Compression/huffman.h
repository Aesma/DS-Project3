#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;
#define buf_size 1024

#include "minheap.h"
#include <QtGui>
#include <iostream>

struct info
{
	uchar ch;
	uint count;
	QString str;
	uint len;
	info() :count(0), len(0){};
	info(info &r)
	{
		ch = r.ch;
		count = r.count;
		str = r.str;
		len = r.len;
	}
	bool operator ==(info& R)
	{
		return ch == R.ch;
	}
	bool operator <=(info& R)
	{
		return count <= R.count;
	}
	bool operator >(info& R)
	{
		return count> R.count;
	}
	info operator +(info& R)
	{
		info tem_info;
		tem_info.count = count + R.count;

		return tem_info;
	}
};

struct HuffmanNode
{
	info data;
	HuffmanNode *leftChild, *rightChild, *parent;
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL){};
	HuffmanNode(info elem, HuffmanNode *left = NULL, HuffmanNode *right = NULL, HuffmanNode *pr = NULL)
		:data(elem), leftChild(left), rightChild(right), parent(pr){};
	bool operator <=(HuffmanNode& R)
	{
		return data <= R.data;
	}
	bool operator >(HuffmanNode& R)
	{
		return data> R.data;
	}
};

class HuffmanTree
{
public:
	HuffmanTree(info w[], int n);
	HuffmanTree(HuffmanTree &hf);
	HuffmanNode* getRoot();
	~HuffmanTree(){ deleteTree(root); };
protected:
	HuffmanNode *root;
	void deleteTree(HuffmanNode *t);
	HuffmanNode* copy(HuffmanNode *orignode);
	void mergeTree(HuffmanNode*& ht1, HuffmanNode*& ht2, HuffmanNode* &parent);
};

#endif