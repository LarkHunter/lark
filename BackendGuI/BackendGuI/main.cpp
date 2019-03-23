#include "BackendGuI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BackendGuI w;
	w.show();
	return a.exec();
}
