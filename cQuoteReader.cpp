#include "cQuoteReader.h"
#include "emotions.h"

QTextStream qin(stdin);
QTextStream qout(stdout);

cQuoteReader::cQuoteReader() {}

qint32 cQuoteReader::cWelcome(void)
{
    qint32 status = 0;
    qout << "Welcome to Daily Quote\n"
         << "Tell us how you're feeling and we'll help you counter this emotion: \n"
         << 0 << ": Sad\n"
         << 1 << ": Happy\n"
         << 2 << ": Angry\n"
         << 3 << ": Calm\n"
         << 4 << ": Bored\n"
         << 5 << ": Excited" << Qt::endl;
    qint32 user_feeling;
    qin >> user_feeling;
    if (user_feeling >= 0 && user_feeling <= 5)
    {
        m_emotion = user_feeling;
        status = 0;
    }
    else
    {
        qout << "Invalid Input." << Qt::endl;
        status = -1;
    }
    return status;
}

void cQuoteReader::cGenerateQuote(void)
{
    QString emotion = opposites[m_emotion]; // match user input to its opposite
    m_eFile = fileName[emotion];  // match the feeling to the file
    QFile file(path + m_eFile);
    if (file.open(QFile::ReadOnly))
    {
        // Load file data
        QByteArray data = file.readAll();
        file.close();

        // Parse the JSON file
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonArray arr = doc.array();

        // Generate a random number and pass it to the JSON array
        quint8 rd = QRandomGenerator::global()->bounded(6);
        QJsonObject item = arr[rd].toObject();
        QString quote = item["quote"].toString();
        QString author = item["author"].toString();
        qout << quote << " - " << author << Qt::endl;
    }
    else
    {
        qout << "File did not open!!" << Qt::endl;
    }
}
