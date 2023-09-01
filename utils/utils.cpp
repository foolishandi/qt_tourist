//
// Created by Administrator on 2023/8/27.
//

#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QApplication>
#include "utils.h"

void CommonUtils::loadQss() {
// 从配置中读取 QSS 的文件名，QSS 可以分类放在多个文件里
    QStringList qssFileNames = {":/resource/qss/test.qss"};
    // 需要把所有文件中的 QSS 合并在一起
    QString qss;

            foreach (QString name, qssFileNames) {
//                中文乱码问题
            qDebug() << QStringLiteral("=> 加载 QSS 文件 %qt_ui_test").arg(name);

            QFile file(name);
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << QStringLiteral("打开 QSS 文件 %qt_ui_test 失败").arg(name);
                continue;
            }

            qss.append(file.readAll()).append("\n");
        }

    if (!qss.isEmpty()) {
        qDebug() << qss;
        qApp->setStyleSheet(qss);
    }
}

QString CommonUtils::getImagesPath(QString imageName) {
    return QString(":/resource/images/%1").arg(imageName);
}

QString CommonUtils::getQmlPath(QString qmlName) {
    return QString("qrc:/resource/qml/%1").arg(qmlName);
}

QString CommonUtils::getQssPath(QString qssName) {
    return QString(":/resource/images/%1").arg(qssName);
}

QString CommonUtils::getHtmlPath(QString htmlName) {
    return QString("qrc:/resource/src/%1").arg(htmlName);
}
