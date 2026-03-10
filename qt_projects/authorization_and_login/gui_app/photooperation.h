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

class UploadPhoto: public PhotoOperation
{
public:
    UploadPhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};

class DeletePhoto: public PhotoOperation
{
public:
    DeletePhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};

class SetAvatarPhoto: public PhotoOperation
{
public:
    SetAvatarPhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};
#endif // PHOTOOPERATION_H
