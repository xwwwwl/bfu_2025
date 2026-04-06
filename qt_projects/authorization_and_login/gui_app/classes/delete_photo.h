#ifndef DELETE_PHOTO_H
#define DELETE_PHOTO_H
#include "photooperation.h"
#include "photo_file_handler.h"
#include "user_file_handler.h"

class DeletePhoto: public PhotoOperation
{
private:
    PhotoFileHandler photo_file_handler_;
    UserFileHandler user_file_handler_;
public:
    DeletePhoto(PhotoFileHandler photo_file_handler, UserFileHandler user_file_handler);
    QString execute(QString login, const QString& photoPath  = "") override;

};

#endif // DELETE_PHOTO_H
