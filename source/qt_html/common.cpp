#include "common.h"
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

//解决QT+VS中文乱码问题
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

MyCommon *MyCommon::self = nullptr;
QTime MyCommon::mTime;

QStringList RET_MSG = QStringList() << "success" << "db connect error" << "SQL error" << "params error"
                                    << "function error" << "type error";

MyCommon::MyCommon(QObject *parent) : QObject(parent)
{
//    注册元类型:主要是在定义信号槽的时候，传递的参数类型不一定是QT所识别的
    qRegisterMetaType<CmdData>("CmdData");
    qRegisterMetaType<RstData>("RstData");
}

MyCommon::~MyCommon()
{
    if (self != nullptr)
    {
        delete self;
    }
}

MyCommon *MyCommon::instance()
{
    if(!self)
    {
        self = new MyCommon();
    }

    return self;
}

QString MyCommon::GetJsonData(const RstData &rstData)
{
    mTime.start();
    QJsonObject dataObj;
    QJsonObject jsObjChild;
    QJsonArray dataArray;
    dataObj.insert("code", rstData.retCode);
    dataObj.insert("msg", rstData.msg);
    dataObj.insert("func", rstData.func);
    int row = rstData.result.size();

    for (int i = 0; i<row; ++i)
    {
        dataArray.append(QJsonArray::fromStringList(rstData.result[i].toList()));
    }

    dataObj.insert("data", dataArray);
    qDebug() << "-----------elapsed: " << mTime.elapsed();
    qDebug() << rstData.result << QJson2QString(dataObj);

    return QJson2QString(dataObj);
}

QString MyCommon::QJson2QString(const QJsonObject &dataObj)
{
    QJsonDocument document(dataObj);
    QByteArray byteArray =document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return strJson;
}

QString MyCommon::QJson2QString(const QJsonArray &dataObj)
{
    QJsonDocument document(dataObj);
    QByteArray byteArray =document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return strJson;
}
