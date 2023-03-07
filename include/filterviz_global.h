#ifndef FILTERVIZ_GLOBAL_H
#define FILTERVIZ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FILTERVIZ_LIBRARY)
#define LIBRARY_EXPORT Q_DECL_EXPORT
#define LIBRARY_EXTERN
#else
#define LIBRARY_EXPORT Q_DECL_IMPORT
#define LIBRARY_EXTERN extern
#endif

#endif // FILTERVIZ_GLOBAL_H