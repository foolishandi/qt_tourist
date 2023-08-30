# qq5_test

## 1 、 qt5 静态编译文件
链接：https://pan.baidu.com/s/11bTlLdUAmsfwqK_uSKLa8g?pwd=3eee
提取码：3eee

## 2 、 静态编译文件使用方式
1) 见主目录CmakeLists.txt
```c++
set(CMAKE_PREFIX_PATH ".../qt-opensource-windows-x86-5.14.qt_ui_test/qt-opensource-windows-x86-5.14.qt_ui_test/5.14.qt_ui_test/msvc2017")
```
2) clion配置编译器

> vs2019社区版，添加vs工具链；
> 
>设置>工具链>架构： amd64_x86；

## 3 、 qt配置相关

1) QDebug不能输出控制台
>编辑配置>环境变量添加 ： QT_ASSUME_STDERR_HAS_CONSOLE=1

2) Qt designer保存的ui文件生成.h文件使用方式
> 将ui文件复制进项目根目录下的uic文件夹

>在uic文件夹内打开cmd，执行下面命令
```c++
./uic.exe xxx.ui -o xxx.h
```
3) 新建类生成测试弹窗
```c++
#include "xxx.h"   //必须添加 "ui_类名.h" 头文件
#include <QDialog>
class testUi:public QDialog,public Ui::Form
{
    Q_OBJECT  //添加 Q_OBJECT宏，为ui类提供信号槽机制
public:
    testUi()
    {
        setupUi(this); //ui类的构造函数中必须包含启动函数，可将代码与界面关联起来。
    }
    ~testUi() override=default;
};
```
4) 测试弹窗
```c++
testUi* p = new testUi();
p->show();
```