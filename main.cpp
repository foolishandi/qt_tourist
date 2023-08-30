#include <QApplication>
#include <QShortcut>
#include "source/my_widget.h"
#include "utils/common_utils.h"
#include <QWindow>
#include <QLoggingCategory>
int main(int argc, char *argv[]) {
    //  qDebug打印信息配置
    qSetMessagePattern("[%{type}] %{time yyyy-MM-dd hh:mm:ss.zzz}  %{function}:%{line} %{message}");

    QApplication app(argc, argv);
    MyWidget test;
    test.setFixedSize(800,400);
    test.show();
    // 加载样式文件
    qInfo() << "qss";
    CommonUtils::loadQss();
//    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), &source);
//    QObject::connect(shortcut, &QShortcut::activated, [] {
//        CommonUtils::loadQss();
//    });

    return QApplication::exec();
}