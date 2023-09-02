# qq5_test

## 1 、 qt5.14 静态编译文件
链接：https://pan.baidu.com/s/1z2i3iyizwTJV8PigAfZXcA?pwd=4k8w
提取码：4k8w

## 2 、 静态编译文件使用方式
1) 见主目录CmakeLists.txt
```c++
set(CMAKE_PREFIX_PATH ".../qt-opensource-windows-x86-5.14.qt_ui_test/qt-opensource-windows-x86-5.14.qt_ui_test/5.14.qt_ui_test/msvc2017")
```
2) clion配置编译器

> vs2019社区版，添加vs工具链，；
> 
>设置>工具链>架构： amd64_x86；
![clion](/example/clion配置.png)
## 3 、 qt配置相关

### (1). QDebug不能输出控制台
>编辑配置>环境变量添加 ： QT_ASSUME_STDERR_HAS_CONSOLE=1

### (2). Qt designer保存的ui文件生成.h文件使用方式
1 )准备工作
> 将ui文件复制进项目根目录下的uic文件夹

>在根目录tool文件夹内打开cmd，执行下面命令
```c++
./uic.exe xxx.ui -o xxx.h
```
2 ) 新建类生成测试弹窗
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
3 ) 测试弹窗
```c++
testUi* p = new testUi();
p->show();
```
### (3)qml+qtQuick使用注意
>example
![listen](/example/listen.png)
1）配置文件需加入
```c++
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Quick
        QuickWidgets
        REQUIRED)
target_link_libraries(qt_test
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Quick
        Qt5::QuickWidgets
)
```
2)qml路径需要加入系统环境变量
![qml配置](/example/qml配置.png)

3)注意QtQuick版本，可以在qtcreator里面新建qt quick项目查看
![qml配置](/example/quick版本.png)

4)qml引入路径要加上`qrc`
```c++
qquickWidget_ = new QQuickWidget;
QUrl source("qrc:/resource/qml/listen.qml");
qquickWidget_->setResizeMode(QQuickWidget::SizeRootObjectToView);
qquickWidget_->setSource(source);
```
5)预览qml文件
>*a.在根目录tool文件夹内点击qmlscene.exe，选择对应的qml文件*
> 
>*b.快速预览  配置外部工具*
![qml快捷](./example/qml快捷.png)
> 
>*c.配置快捷键*
![qml快捷键](./example/qml快捷键.png)
> 
>*d.在编辑qml时直接按shift+q即可实时看到qt界面*

## (4)加载react文件
>1>qt配置相关
- cmake添加配置
```c++
find_package(Qt5 COMPONENTS Widgets Network LinguistTools)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
        WebChannel
        REQUIRED)
target_link_libraries(qt_test
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebEngineWidgets
        Qt5::WebChannel
)
```
- 若构建失败需配置：
```c++
  (1) Resources 配置
  将Qt对应版本下的Resources的拷贝到 自己库下的 Resources 目录
```
```c++
icudtl.dat
qtwebengine_devtools_resources.pak
qtwebengine_resources.pak
qtwebengine_resources_100p.pak
qtwebengine_resources_200p.pak
```
```c++
(2) translations 配置
将Qt对应版本下的translations 的 拷贝到 自己库下的 translations 目录
(3) QtWebEngineProcess.exe 配置
将Qt对应版本下的QtWebEngineProcess.exe 的 拷贝到 自己库下
(4) plugins 配置
将Qt对应版本下的plugins 的 拷贝到 自己库下plugins 目录
(5) qt.conf 文件配置
将Qt对应版本下的qt.conf的 拷贝到 自己库下,并更改 qt.conf 如下
```
```c++
[Paths]
Plugins = ./plugins
Resources = ./Resources
translations = ./translations
```
- 最简单的QT 添加代码
```c++
QWebEngineView *view = new QWebEngineView(parent);
view->load(QUrl("https://www.csdn.net/"));
view->show();
```
>2>react等web前端配置相关
- 写好前端项目文件，利用build命令生成打包文件
- cmd,利用本项目根目录下的tool内的qrc.exe生成qrc文件，并引入qrc文件
```c++
./qrc.exe xxx  //xxx即为对应的build文件夹
```
- 引入index.html的时候注意引入地址

a.因为react打包时用的相对地址,因此最好把qrc的前缀地址去掉

b.或者同时修改react打包的output地址，添加前缀
```c++
view->load(QUrl("qrc:/index.html"));
```

## (5)简易打包软件
- release build构建
- 将生成的xxx.exe单独复制到一个空的文件夹
- cmd,利用本项目根目录下的tool内的windeployqt.exe找出xxx.exe所需的所有动态库（需要qt环境，是全量动态库引入，包含不需要的）
```c++
./windeployqt.exe xxx.exe
```
- 利用本项目根目录下的tool内的Inno Setup v6.2.0.exe，按照向导生成整个文件夹的压缩可执行文件

- [使用教程](https://blog.csdn.net/jg_csdn/article/details/124693110?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169361655316800186544935%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169361655316800186544935&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-124693110-null-null.142^v93^insert_down28v1&utm_term=inno%20setup&spm=1018.2226.3001.4187)