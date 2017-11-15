#include "compress.h"

Compress::Compress(QString fileName,uint64 sz)
{
	code = "";
	rec = 0;
	fileSize = sz;
	filePath = fileName + ".fuck_huf";
	file.setFileName(filePath);
	file.open(QIODevice::WriteOnly);
}

bool Compress::creatHuffman(QByteArray ch)
{
	info *tem_info = new info[fileSize];

	for (int i = 0; i < ch.length(); i++)
		tem_info[i].ch = ch[i];
	for (int i = 0; i < 256; i++)
		ainfo[i].ch = i;
	for (int j = 0; j < ch.length(); j++)
	{
		ainfo[tem_info[j].ch].count++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (ainfo[i].count != 0)
			rec++;
	}

	info_tree = new info[rec];
	rec = 0;

	for (int i = 0; i < 256; i++)
	{
		if (ainfo[i].count != 0)
			info_tree[rec++] = ainfo[i];
	}

	HuffmanTree tem_tree(info_tree, rec);
	root = tem_tree.getRoot();
	throughTree(root);
	outTree();

	delete[]tem_info;

	return true;
}

bool Compress::com(QByteArray ch)
{
	QDataStream out(&file);

	for (int i = 0; i < ch.size(); i++)
	{
		uchar tem = ch[i];
		all_code += ainfo[tem].str;
	}

	while (all_code != "")
	{
		QString str_e = all_code.left(32);
		all_code = all_code.right(all_code.length() - 32);
		uint aa = qstoi(str_e);
		out << aa;
	}

	return true;
}

void Compress::inputSizeNum(uint n, uint re)
{
	QDataStream out(&file);
	buf_num = n;
	buf_rem = re;
	out << buf_num << buf_rem;
}

bool Compress::throughTree(HuffmanNode *&r)
{
	if (r == NULL)
		return false;
	if (r->leftChild == NULL&&r->rightChild == NULL){
		ainfo[r->data.ch].str = code;
		ainfo[r->data.ch].len = code.length();

		return true;
	}

	code.append("0");
	throughTree(r->leftChild);
	code = code.left(code.length() - 1);
	code.append("1");
	throughTree(r->rightChild);
	code = code.left(code.length() - 1);

	return true;
}

void Compress::outTree()
{
	QDataStream out(&file);
	out << rec;
	for (int i = 0; i < 256; i++)
	{
		if (ainfo[i].count != 0){
			uint temp = ainfo[i].ch;
			out << temp << ainfo[i].count;
		}
	}
}

uint Compress::qstoi(QString str)
{
	bool lalala;
	uint tem_int = str.toUInt(&lalala, 2);
	if (str.size() < 32){
		int shift = 32 - str.size();
		tem_int <<= shift;
	}

	return tem_int;
}

Compress::~Compress()
{
	file.close();
}