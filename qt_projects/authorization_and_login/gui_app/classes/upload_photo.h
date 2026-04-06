#ifndef UPLOAD_PHOTO_H
#define UPLOAD_PHOTO_H
#include "photooperation.h"
#include "photo_file_handler.h"
#include "user_file_handler.h"
class UploadPhoto: public PhotoOperation
{
private:
    UserFileHandler user_file_handler_;
    PhotoFileHandler photo_file_handler_;
public:
    UploadPhoto(PhotoFileHandler photo_file_handler,UserFileHandler user_file_handler);
    QString execute(QString login, const QString& photoPath  = "") override;

};

#endif // UPLOAD_PHOTO_H
