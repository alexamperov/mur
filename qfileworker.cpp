#include "qfileworker.h"

QFileWorker::QFileWorker(QObject *parent) : QObject(parent)
{

}

bool QFileWorker::openFile(QString fn, QIODevice::OpenMode mode)
{
	dataFile.setFileName(fn);
	if (dataFile.open(mode)) {
		stream.setDevice(&dataFile);
		stream.setVersion(QDataStream::Qt_4_8);
		keyOffset = 0;
		return true;
	} else {
		return false;
	}
}

void QFileWorker::closeFile()
{
	dataFile.close();
}

void QFileWorker::setStr(QString data)
{
	stream << crypt(data);
}

void QFileWorker::setInt(int data)
{
	stream << crypt(QString::number(data));
}

QString QFileWorker::getStr()
{
	stream >> buffer;
	return crypt(buffer);
}

QChar QFileWorker::getChr()
{
	stream >> buffer;
	return crypt(buffer)[0];
}

int QFileWorker::getInt()
{
	stream >> buffer;
	return crypt(buffer).toInt();
}

QString QFileWorker::crypt(QString data)
{
	QString result;
	for (int i = 0; i < data.count(); i++) {
		result += QChar(data[i].unicode() ^ keyPhrase[keyOffset].unicode());
		shiftKeyOffset();
	}
	return result;
}

void QFileWorker::shiftKeyOffset()
{
	if (keyPhrase.count() != keyOffset)
		keyOffset++;
	else
		keyOffset = 0;
}
