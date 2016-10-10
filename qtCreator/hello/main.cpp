#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mString = " x hello world x" << endl;

    qDebug() << mString << endl;


    return a.exec();
}

