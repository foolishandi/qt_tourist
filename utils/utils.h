//
// Created by Administrator on 2023/8/27.
//

#ifndef QT_TEST_UTILS_H
#define QT_TEST_UTILS_H


#include <QString>

class CommonUtils {
public:
   static void loadQss();
    static QString getImagesPath(QString imageName);
    static QString getQmlPath(QString qmlName);
    static QString getQssPath(QString qssName);
    static QString getHtmlPath(QString htmlName);
};


#endif //QT_TEST_UTILS_H
