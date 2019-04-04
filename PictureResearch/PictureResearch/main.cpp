#include "PictureResearch.h"
#include "BmpProcess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PictureResearch w;
	w.show();
	return a.exec();
}
