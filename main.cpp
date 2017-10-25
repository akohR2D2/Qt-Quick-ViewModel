#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include "cpuInfoModel.h"
#include "FileReader/fileReader.h"
#include "mainModel.h"

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    FileReader* fileReader = new FileReader();

    MainModel mainModel(fileReader);;

    QQmlApplicationEngine engine;

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) return -1;

    QQmlContext *dataContext = engine.rootContext();
    dataContext->setContextProperty("mainModel", QVariant::fromValue((QObject*)&mainModel));

    return app.exec();
}
