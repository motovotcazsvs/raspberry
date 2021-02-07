#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include "bye.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
    app.setFont(QFont("DejaVu Sans"));

    QQmlApplicationEngine engine;

    QQmlContext* ctx = engine.rootContext();
    Bye shut;
    ctx->setContextProperty("context", &shut);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
