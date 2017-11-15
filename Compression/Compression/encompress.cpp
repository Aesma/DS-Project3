#include "encompress.h"

Decode::Decode(info t[], int r, QString fileName)
{
	rec = r;
	code = "";
	num = 0;
	file_num = 0;
	file_size = buf_size;
	tree = new info[rec];
	filePath = fileName;
	file.setFileName(filePath);
	file.open(QIODevice::WriteOnly);

	for (int i = 0; i < rec; i++)
		tree[i] = t[i];

	HuffmanTree tem_tree(tree, rec);
	root = tem_tree.getRoot();
}

void Decode::enCom(uint x)
{
	QString str = itoqs(x);
	code += str;
	decode();
}

bool Decode::decode()
{
	QDataStream out(&file);
	while (code != "")
	{
		uchar ch;
		if (getCh(code, ch)){
			out << ch;
			if (code == ""&&num == file_size){
				num = 0;
				file_num++;
				if (file_num == buf_num){
					file_size = buf_rem;
				}
			}
		}
		else
			return false;
	}

	return true;
}

bool Decode::getCh(QByteArray &byte,uchar &ch)
{
	int count = 0;
	HuffmanNode *tem_huf = root;
	
	while (tem_huf->leftChild != NULL&&tem_huf->rightChild != NULL)
	{
		uchar temp = byte[count++];

		if (temp != '0'&&temp != '1'){
			if (num == file_size){
				code = "";
				num = 0;
				file_num++;
				if (file_num == buf_num){
					file_size = buf_rem;
				}
			}
			return false;
		}
		if (temp == '0')
			tem_huf = tem_huf->leftChild;
		else
			tem_huf = tem_huf->rightChild;
	}
	
	num++;

	if (num > file_size){
		byte = "";
		num = 0;
		file_num++;
		if (file_num == buf_num){
			file_size = buf_rem;
		}
		return false;
	}

	ch = tem_huf->data.ch;
	byte = byte.right(byte.size() - count);

	return true;
}

void Decode::inputSizeRem(uint n, uint r)
{
	buf_num = n;
	buf_rem = r;
	if (buf_num == 0)
		file_size = buf_rem;
}
QString Decode::itoqs(uint x)
{
	QString qstr;
	for (int i = 0; i < 32; i++)
	{
		uint temp;
		temp = x << i;
		temp >>= 31;

		if (temp == 0)
			qstr += '0';
		else
			qstr += '1';
	}

	return qstr;
}

Decode::~Decode()
{
	delete[]tree;
	file.close();
}