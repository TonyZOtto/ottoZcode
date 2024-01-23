#include "URL.h"

Url::Url() {;}

Url::Url(const QString &url, ParsingMode parsingMode)
    : QUrl(url, parsingMode) {;}
