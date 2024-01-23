#pragma once

#include <QUrl>

class Url : public QUrl
{
public: // ctors
    Url();
    Url(const QString &url,
        QUrl::ParsingMode parsingMode=TolerantMode);

public: // const


public: // non-const

};
