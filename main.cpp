#include <QCoreApplication>
#include <QTextStream>
#include "cQuoteReader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cQuoteReader q1;
    if (!q1.cWelcome())
    {
       // if the user input is valid, start the quote generator
       q1.cGenerateQuote();
    }

    return a.exec();
}
