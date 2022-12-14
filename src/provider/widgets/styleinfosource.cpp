/*
    Copyright (C) 2017 Volker Krause <vkrause@kde.org>

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "styleinfosource.h"

#include <QApplication>
#include <QPalette>
#include <QStyle>
#include <QVariant>

using namespace KUserFeedback;

StyleInfoSource::StyleInfoSource()
    : AbstractDataSource(QStringLiteral("style"))
{
}

QString StyleInfoSource::description() const
{
    return tr("The widget style used by the application, and information about the used color scheme.");
}

QVariant StyleInfoSource::data()
{
    QVariantMap m;
    if (qApp && qApp->style())
        m.insert(QStringLiteral("style"), qApp->style()->objectName()); // QStyleFactory sets the object name to the style name
    m.insert(QStringLiteral("dark"), qApp->palette().color(QPalette::Background).lightness() < 128);
    return m;
}

QString StyleInfoSource::name() const
{
    return tr("Application style");
}
