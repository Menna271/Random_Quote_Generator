#ifndef CQUOTE_H
#define CQUOTE_H

#include <QFile>
#include <QMap>
#include <QRandomGenerator>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class cQuoteReader
{
public:
    cQuoteReader();
    qint32 cWelcome();
    void cGenerateQuote();

private:
    const QString path = "d:/Qt/Qt_Workspace/Quote_Generator/Emotion_Dir/"; // Directory path
    QString m_eFile;  // File Name
    qint32 m_emotion; // User input that matches their feeling
};

#endif // CQUOTE_H
