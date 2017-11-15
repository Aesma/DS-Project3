#include "compression.h"

Compression::Compression(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	dealDialog();
}

void Compression::dealDialog()
{
	inputLine->setReadOnly(true);

	progressBar->setValue(0);

	connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(comButton, SIGNAL(clicked()), this, SLOT(doCom()));
	connect(uncomButton, SIGNAL(clicked()), this, SLOT(enCom()));

	setWindowIcon(QIcon("favicon.ico"));
	setWindowTitle(tr("Fuck Huffman"));
}

void Compression::openFile()
{
	fileName = QFileDialog::getOpenFileName(
		this,
		"Open Document",
		QDir::currentPath(),
		"All files(*.*)");
	if (fileName == ""){
		QMessageBox::warning(this, tr("Error"),
			tr("没有读取文件!"));
		return;
	}

	progressBar->setValue(0);
	inputLine->setText(fileName);
}

bool Compression::doCom()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");

	double count = 0;

	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, tr("Error"),
			tr("压缩文件失败!"));

		return false;
	}

	uint64 size = file.size();
	uint buf_num = size / buf_size;
	uint buf_rem = size % buf_size;
	Compress com(fileName,size);
	com.inputSizeNum(buf_num, buf_rem);
	QByteArray byte = file.readAll();
	com.creatHuffman(byte);//因为这里是一次性建的树··所以点了压缩之后会直接卡住·要有耐心~

	file.seek(0);

	while (!file.atEnd())
	{
		QByteArray tem_qbyte = file.read(buf_size);
		com.com(tem_qbyte);
		count++;
		int temp = 100 * count * buf_size / (size * 2);

		if (temp > 100)
			temp = 100;

		progressBar->setValue(temp);
	}
	
	progressBar->setValue(100);

	QMessageBox::information(this, tr("Success"),
		tr("压缩完成!"));

	file.close();

	return true;
}

bool Compression::enCom()
{
	QFileInfo fileinfo = QFileInfo(fileName);
	QString file_suffix = fileinfo.suffix();

	if (file_suffix != "fuck_huf"){
		QMessageBox::warning(this, tr("Error"),
			tr("该文件不是压缩后的文件!"));

		return false;
	}

	QTextCodec *codec = QTextCodec::codecForName("GBK");

	double count = 0;

	QFile file(fileName);
	QDataStream in(&file);

	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, tr("Error"),
			tr("压缩文件失败!"));

		return false;
	}
	
	int tem;
	uint64 size = file.size();
	uint buf_num, buf_rem;
	in >> buf_num >> buf_rem;
	int rec;
	in >> rec;
	info *t = new info[rec];
	
	for (int i = 0; i < rec; i++)
	{
		uint temp;
		in >> temp >> t[i].count;
		t[i].ch = temp;
		count++;
		tem = 100 * count * (sizeof(uint) * 2) / size;
		progressBar->setValue(tem);
	}

	int index = fileName.lastIndexOf(".");
	fileName.truncate(index);
	Decode decode(t, rec, fileName);
	decode.inputSizeRem(buf_num, buf_rem);
	count = 0;

	while (!file.atEnd())
	{
		uint tem_int;
		in >> tem_int;
		decode.enCom(tem_int);
		count++;
		int temp = tem + 100 * count * sizeof(uint) / size;

		if (temp > 100)
			temp = 100;

		progressBar->setValue(temp);
	}

	progressBar->setValue(100);

	QMessageBox::information(this, tr("Success"),
		tr("解压成功!"));

	delete[]t;

	return true;
}

void Compression::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.drawPixmap(0, 0, width(), height() - 50, QPixmap("fuck.jpeg"));
}

Compression::~Compression()
{

}