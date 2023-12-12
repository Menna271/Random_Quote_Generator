#ifndef EMOTIONS_H
#define EMOTIONS_H

#include<QMap>

// The map order is the opposite to the welcome msg preseted to the user
QMap<qint32, QString> opposites = {
    {0, "Happy"},
    {1, "Sad"},
    {2, "Calm"},
    {3, "Angry"},
    {4, "Excited"},
    {5, "Bored"}
};

// Matches each feeling to its emotion file
QMap<QString, QString> fileName = {
    {"Sad",     "Sad.json"},
    {"Happy",   "Happy.json"},
    {"Angry",   "Angry.json"},
    {"Calm",    "Calm.json"},
    {"Bored",   "Bored.json"},
    {"Excited", "Excited.json"}
};

#endif // EMOTIONS_H
