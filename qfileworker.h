#ifndef QFILEWORKER_H
#define QFILEWORKER_H

#include <QObject>
#include <QDataStream>
#include <QFile>

class QFileWorker : public QObject
{
	Q_OBJECT

public:
	explicit QFileWorker(QObject *parent = 0);
	bool openFile(QString fn, QIODevice::OpenMode mode);
	void closeFile();
	QString getStr();
	QChar getChr();
	int getInt();
	void setStr(QString data);
	void setInt(int data);


protected:
	QString crypt(QString data);
	void shiftKeyOffset();

private:
	QString buffer;
	QFile dataFile;
	QDataStream stream;
	QString keyPhrase = "Ы7м:чpТfрь}Kг%rЪqЯм!СМCР17.ЕPЬЫдФКдРxзШ2MFЮ{NЪCБbь+e,бUg0i3ЩCцHы";
	int keyOffset = 0;

};

#endif // QFILEWORKER_H
