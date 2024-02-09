#ifndef KEYSEG_H
#define KEYSEG_H

#include "AText.h"

#include <QChar>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class KeySeg : public AText
{
public:
    explicit KeySeg();
    KeySeg(const char * pch) { set(pch); }
    KeySeg(const AText atx) { set(atx); }
    KeySeg(const QString qs) { set(qs); }

public: // const


public: // non-const
    void set(const char * pch);
    void set(const AText atx);
    void set(const QString qs);


private: // static
    static char validFirstChar(const char ch);
    static char validNextChar(const char ch);
};

inline void KeySeg::set(const char *pch)
{
    set(AText(pch));
}

inline void KeySeg::set(const QString qs)
{
    set(AText(qs));
}

inline char KeySeg::validFirstChar(const char ch)
{
    char result('_');
    static const QRegularExpression scFirstCharsRE("[_$ABCDEFGHIJKLMNOPQRSTUVWXYZ]",
                                                   QRegularExpression::CaseInsensitiveOption);
    const QRegularExpressionMatch cFirstREMatch = scFirstCharsRE.match(QString(ch));
    if (cFirstREMatch.isValid()) result = ch;
    return result;
}

inline char KeySeg::validNextChar(const char ch)
{
    char result('_');
    static const QRegularExpression scNextCharsRE("[0123456789_$ABCDEFGHIJKLMNOPQRSTUVWXYZ]",
                                                  QRegularExpression::CaseInsensitiveOption);
    const QRegularExpressionMatch cNextREMatch = scNextCharsRE.match(QString(ch));
    if (cNextREMatch.isValid()) result = ch;
    return result;
}

#endif // KEYSEG_H
