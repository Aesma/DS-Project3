#ifndef COMPRESSION_H
#define COMPRESSION_H

#include "ui_compression.h"
#include "compress.h"
#include "encompress.h"

#include <QtGui>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QByteArray>
#include <QtWidgets/QDialog>

class Compression : public QDialog, public Ui::CompressionClass
{
	Q_OBJECT
public:
	Compression(QWidget *parent = 0);
	~Compression();
protected:
	void dealDialog();
private slots:
	void openFile();
	bool doCom();
	bool enCom();
private:
	void paintEvent(QPaintEvent *event);
private:
	uchar *data;
	QString fileName;
};

#endif // COMPRESSION_H
