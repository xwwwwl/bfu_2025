#ifndef UPLOAD_PHOTO_H
#define UPLOAD_PHOTO_H
#include "photooperation.h"
class UploadPhoto: public PhotoOperation
{
public:
    UploadPhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};

#endif // UPLOAD_PHOTO_H
