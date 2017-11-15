#include <QtGui>

#include "myclass.h"

MyClass::MyClass(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);

	fTree = "";
	h_count = 0;
	tempH = 0;
	tempW = 0;
	isW = false;
	isPlus = false;
	dealDialog();
}

void MyClass::dealDialog()
{
	parentLine->setReadOnly(true);
	graLine->setReadOnly(true);
	firstPreLine->setText(tr("����ǰ������"));
	levelLine->setText(tr("����������"));
	findLine->setText(tr("����Ҫ���ҵĽ��"));
	secondPreLine->setText(tr("����ǰ������"));
	inorderLine->setText(tr("������������"));

	connect(findButton, SIGNAL(clicked()), this, SLOT(doFind()));
	connect(swapButton, SIGNAL(clicked()), this, SLOT(doSwap()));
	connect(getTreeButton, SIGNAL(clicked()), this, SLOT(makeTree()));
}

void MyClass::paintEvent(QPaintEvent *event)
{
	h_count = 0;
	isPlus = false;
	if (fTree != ""){
		for (int i = 0; i < h_tree; i++)
			w_count[i] = 0;
		dealHcount(root);
		h_count = 0;
		dealWcount(root);
		h_count = 0;
		paintPreTree(root);
	}
}

bool MyClass::doFind()
{
	QString pre = firstPreLine->text();
	QString level = levelLine->text();
	QString qchild = findLine->text();
	char* child = new char[1];
	string stdStr;
	if ((pre == "" || pre == "����ǰ������") && (level == "" || level == "����������")){
		QMessageBox::warning(this, tr("����!"),
			tr("û��������!"));
		return false;
	}
	if (!(pre == "" || pre == "����ǰ������") && !(level == "" || level == "����������")){
		QMessageBox::warning(this, tr("����!"),
			tr("�޷��ж�Ҫ�����ǿ���!"));
	}
	if (qchild == "" || qchild == "����Ҫ���ҵĽ��"){
		QMessageBox::warning(this, tr("����!"),
			tr("û������Ҫ���ҵĽ��!"));
	}
	else{
		qchild = qchild.left(1);
		stdStr = qchild.toStdString();
		child = (char*)stdStr.c_str();
	}
	if (!(pre == "" || pre == "����ǰ������")){
		find.doFind(pre, child[0]);
		find.getParent(parent);
		QString parentStr = "�����:";
		for (int i = 1; i < parent.length(); i++)
		{
			parentStr += (QString(parent[i].data) + " ");
		}
		parentLine->setText(parentStr);
		fTree = pre;
	}
	else if (!(level == "" || level == "����������")){
		find.doLevelFind(level, child[0]);
		find.getParent(parent);
		QString parentStr = "�����:";
		for (int i = 1; i < parent.length(); i++)
		{
			parentStr += (QString(parent[i].data) + " ");
		}
		parentLine->setText(parentStr);
		fTree = level;
	}
	root = find.getRoot();
	h_tree = find.Height() + 1;
	w_count = new int[h_tree];
	isW = true;

	update();

	return true;
}

bool MyClass::doSwap()
{
	QString pre = firstPreLine->text();
	QString level = levelLine->text();
	if ((pre == "" || pre == "����ǰ������") && (level == "" || level == "����������")){
		QMessageBox::warning(this, tr("����!"),
			tr("û��������!"));
		return false;
	}
	if (!(pre == "" || pre == "����ǰ������")){
		find.doSwap(pre);
		parentLine->setText("������:" + pre);
		fTree = pre;
	}
	else if (!(level == "" || level == "����������")){
		find.doLevelSwap(level);
		parentLine->setText("������:" + level);
		fTree = level;
	}
	root = find.getRoot();
	h_tree = find.Height() + 1;
	w_count = new int[h_tree];
	isW = true;

	update();

	return true;
}

bool MyClass::makeTree()
{
	QString pre = secondPreLine->text();
	QString inorder = inorderLine->text();
	ensureTree(root, pre, inorder);
	QString str = "";
	str = make.getLevelStr();
	graLine->setText(str);
	h_tree = make.getHeight();
	fTree = str;
	w_count = new int[h_tree];

	update();

	return true;
}

void MyClass::ensureTree(BinTreeNode<char>*&r, QString preTree, QString inorderTree)
{
	make.ensureTree(preTree, inorderTree);
	make.getRoot(r);
}

void MyClass::paintPreTree(BinTreeNode<char>*r)
{
	int w = firstBox->width();
	int w2 = width() - w;
	int h = height();
	QPainter painter(this);
	if (r == NULL){
		return;
	}
	else{
		QString qs = r->data;
		painter.setPen(Qt::black);
		if (r->leftChild != NULL){
			painter.drawLine(w + h / (h_tree * 4) + (r->w * w2) / (pow(2, r->h - 1) + 1), h / (h_tree * 4) + (r->h - 1) * h / h_tree, w + h / (h_tree * 4) + (r->leftChild->w * w2) / (pow(2, r->leftChild->h - 1) + 1), h / (h_tree * 4) + (r->leftChild->h - 1) * h / h_tree);
		}
		if (r->rightChild != NULL){
			painter.drawLine(w + h / (h_tree * 4) + (r->w * w2) / (pow(2, r->h - 1) + 1), h / (h_tree * 4) + (r->h - 1) * h / h_tree, w + h / (h_tree * 4) + (r->rightChild->w * w2) / (pow(2, r->rightChild->h - 1) + 1), h / (h_tree * 4) + (r->rightChild->h - 1) * h / h_tree);
		}
		painter.setBrush(Qt::green);
		if (r->data == 35)
			painter.setBrush(Qt::red);
		painter.drawEllipse(w + (r->w * w2) / (pow(2, r->h - 1) + 1), (r->h - 1) * h / h_tree, h / (h_tree * 2), h / (h_tree * 2));
		painter.drawText(QPoint(w + h / (h_tree * 4) + (r->w * w2) / (pow(2, r->h - 1) + 1), h / (h_tree * 4) + (r->h - 1) * h / h_tree), qs);
		paintPreTree(r->leftChild);
		paintPreTree(r->rightChild);
	}
}

void MyClass::dealWcount(BinTreeNode<char>*&r)
{
	if (h_count < h_tree){
		if (r == NULL){
			h_count++;
			return;
		}
		else{
			h_count++;
			dealWcount(r->leftChild);
			if (r->leftChild == NULL&&!isPlus){
				tempH = h_count;
				tempW = r->w;
				node = r;
				wcountPlus(root);
				isPlus = true;
			}
			h_count--;
			dealWcount(r->rightChild);
			h_count--;
		}
	}
}

void MyClass::dealHcount(BinTreeNode<char>*&r)
{
	if (h_count <= h_tree){
		if (r == NULL){
			w_count[h_count]++;
			h_count++;
			return;
		}
		else{
			w_count[h_count]++;
			h_count++;
			r->h = h_count;
			r->w = w_count[h_count - 1];
			dealHcount(r->leftChild);
			h_count--;
			dealHcount(r->rightChild);
			h_count--;
		}
	}
}

void MyClass::wcountPlus(BinTreeNode<char>*&r)
{
	if (r == NULL){
		return;
	}
	else{
		if (r->h > tempH&&r->w >= tempW){
			r->w += pow(2, r->h - tempH);
			if (node->rightChild == NULL){
				r->w += pow(2, r->h - tempH);
			}
		}
		wcountPlus(r->leftChild);
		wcountPlus(r->rightChild);
	}
}

MyClass::~MyClass()
{
	if (isW)
		delete[]w_count;
}
