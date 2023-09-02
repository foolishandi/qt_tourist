//
// Created by Administrator on 2023/9/2.
//

#ifndef QT_EXPORT_H_
#define QT_EXPORT_H_

#ifdef BUILD_EXPORT
#define QT_EXPORT Q_DECL_EXPORT
#else
#ifdef BUILD_IMPORT
#define QT_EXPORT Q_DECL_IMPORT
#else
#define QT_EXPORT
#endif
#endif

#endif // QT_EXPORT_H_
