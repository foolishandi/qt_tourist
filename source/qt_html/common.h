//
// Created by Administrator on 2023/9/1.
//

#ifndef QT_TEST_COMMON_H
#define QT_TEST_COMMON_H
#include <QObject>
#include <QMap>
enum RET_CODE {
    RET_OK = 0,
    RET_DBERR_OPEN,
    RET_DBERR_RUN,
    RET_PARAMERR,
    RET_NOFUNC,
    RET_NOWORKTYPE
};

extern QStringList RET_MSG;

typedef struct _CmdData {
    QString func;
    QMap<QString, QString> params;
} CmdData;

typedef struct _RstData {
    int retCode;
    QString func;
    QString msg;
    QVector< QVector<QString> > result;
} RstData;

class MyCommon : public QObject
{
    Q_OBJECT
public:
    explicit MyCommon(QObject *parent = nullptr);
    ~MyCommon();

    static MyCommon *instance();
    static QString GetJsonData(const RstData &rstData);
    static QString QJson2QString(const QJsonObject &dataObj);
    static QString QJson2QString(const QJsonArray &dataObj);

private:
    static MyCommon *self;//单例模式
    static QTime mTime;

};
#endif //QT_TEST_COMMON_H
