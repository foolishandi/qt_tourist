//
// Created by Administrator on 2023/8/30.
//

#ifndef QT_TEST_QML_TEST_H
#define QT_TEST_QML_TEST_H
#include <QDialog>
#include <QQuickWidget>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class QmlTEST : public QDialog
{
Q_OBJECT

public:
    QmlTEST(QWidget *parent = nullptr);
    ~QmlTEST()=default;

    void setTitle(const QString &title);
    void setTotal(const long v);
    void setCurValue(const long v);
signals:
    void sigPalyProgress(qreal v);
public slots:
    void onSliderMoved(qreal v);
    void onPlay();
    void onPause();
private:
    QQuickWidget* qquickWidget_;
    QVBoxLayout layout_;
};
#endif //QT_TEST_QML_TEST_H
