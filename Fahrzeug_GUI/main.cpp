#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "fahrverhalten.h"
#include "steuereinheit.h"
#include "fahrzeuginfo.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Fahrverhalten>("SDLF.com",1,0,"Fahrverhalten");
    qmlRegisterType<FahrzeugInfo>("SDLF.com",1,0,"FahrzeugInfo");
    qmlRegisterType<Steuereinheit>("SDLF.com",1,0,"Steuereinheit");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
