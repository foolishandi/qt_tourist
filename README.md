# qq5_test

## 1 、 qt5 静态编译文件
链接：https://pan.baidu.com/s/11bTlLdUAmsfwqK_uSKLa8g?pwd=3eee
提取码：3eee

## 2 、 静态编译文件使用方式
1) 见主目录CmakeLists.txt
```c++
set(CMAKE_PREFIX_PATH ".../qt-opensource-windows-x86-5.14.1/qt-opensource-windows-x86-5.14.1/5.14.1/msvc2017")
```
2) clion配置编译器

> vs2019社区版，添加vs工具链；
> 
>设置>工具链>架构： amd64_x86；

## 3 、 qt配置相关

1) QDebug不能输出控制台
>编辑配置>环境变量添加 ： QT_ASSUME_STDERR_HAS_CONSOLE=1