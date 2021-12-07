#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "fearGreedChart.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // FearGreedChart 1.0
    qmlRegisterType<FearGreedChart>("FearGreedChart", 1, 0, "FearGreedChart");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/FearGreedChart/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
