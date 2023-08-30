#include <QApplication>
#include <QShortcut>
#include "source/my_widget.h"
#include "utils/common_utils.h"
#include <QWindow>
#include <QLoggingCategory>
#include <QQmlApplicationEngine>
//中文乱码问题
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
int main(int argc, char *argv[]) {
    //  qDebug打印信息配置
    qSetMessagePattern("[%{type}] %{time yyyy-MM-dd hh:mm:ss.zzz}  %{function}:%{line} %{message}");
    //  高分辨率支持
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    MyWidget test;
    test.setFixedHeight(400);
    test.show();
    // 加载样式文件
    qInfo() << "qss";
    CommonUtils::loadQss();
//    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), &source);
//    QObject::connect(shortcut, &QShortcut::activated, [] {
//        CommonUtils::loadQss();
//    });

// qml主程序方式
//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral(":/resource/qml/test0.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//                if (!obj && url == objUrl)
//                    QCoreApplication::exit(-1);
//            }, Qt::QueuedConnection);
//    engine.load(url);
    return QApplication::exec();
}