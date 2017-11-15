#ifndef ENCOMPRESS_H
#define ENCOMPRESS_H

#include "huffman.h"
#include <QFile>

class Decode
{
public:
	Decode(info t[], int re, QString fileName);
	void enCom(uint x);
	void inputSizeRem(uint n, uint r);
	~Decode();
protected:
	QString itoqs(uint x);
	bool getCh(QByteArray &byte,uchar &ch);
	bool decode();
private:
	QByteArray code;
	QString filePath;
	info *tree;
	HuffmanNode *root;
	int rec;
	int num;
	uint buf_num;
	uint buf_rem;
	uint file_num;
	uint file_size;
	QFile file;
};

#endif