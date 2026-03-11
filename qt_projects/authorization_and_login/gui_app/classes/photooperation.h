#ifndef PHOTOOPERATION_H
#define PHOTOOPERATION_H
#include "user_class.h"
#include <QString>
class PhotoOperation
{
public:
    PhotoOperation() = default;
    virtual ~PhotoOperation() = default;
    virtual QString execute(User* user, const QString& photoPath  = "") =0;

};
#endif // PHOTOOPERATION_H
