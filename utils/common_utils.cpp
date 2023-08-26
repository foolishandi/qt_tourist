//
// Created by Administrator on 2023/8/27.
//

#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QApplication>
#include "common_utils.h"

void CommonUtils::loadQss() {
// 从配置中读取 QSS 的文件名，QSS 可以分类放在多个文件里
    QStringList qssFileNames = {":/resource/qss/test.qss"};
    // 需要把所有文件中的 QSS 合并在一起
    QString qss;

            foreach (QString name, qssFileNames) {
//                中文乱码问题
            qDebug() << QStringLiteral("=> 加载 QSS 文件 %1").arg(name);

            QFile file(name);
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << QStringLiteral("打开 QSS 文件 %1 失败").arg(name);
                continue;
            }

            qss.append(file.readAll()).append("\n");
        }

    if (!qss.isEmpty()) {
        qDebug() << qss;
        qApp->setStyleSheet(qss);
    }
}
