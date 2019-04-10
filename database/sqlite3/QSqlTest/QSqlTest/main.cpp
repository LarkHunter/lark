#include "QSqlTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSqlTest w;
	w.show();
	return a.exec();
}
