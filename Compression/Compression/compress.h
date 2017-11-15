#ifndef COMPRESS_H
#define COMPRESS_H

#include "huffman.h"
#include <QtGui>
#include <QFile>
#include <QDataStream>
#include <QVector>
#include <cmath>
#include <cstdlib>

class Compress
{
public:
	Compress(QString fileName, uint64 sz);
	bool com(QByteArray ch);
	bool creatHuffman(QByteArray ch);
	void inputSizeNum(uint n, uint re);
	HuffmanNode *getRoot();
	~Compress();
protected:
	bool throughTree(HuffmanNode *&r);
	void outTree();
	uint qstoi(QString str);
private:
	int rec;
	uint buf_num;
	uint buf_rem;
	uint64 fileSize;
	info ainfo[256];
	info *info_tree;
	QString code;
	HuffmanNode *root;
	QString filePath;
	QByteArray all_code;
	QFile file;
};

#endif