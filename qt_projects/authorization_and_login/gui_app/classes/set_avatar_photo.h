#ifndef SET_AVATAR_PHOTO_H
#define SET_AVATAR_PHOTO_H
#include "photooperation.h"
#include "user_file_handler.h"
class SetAvatarPhoto: public PhotoOperation
{
private:

    UserFileHandler user_file_handler_;
public:
    SetAvatarPhoto(UserFileHandler user_file_handler);
    QString execute(QString login, const QString& photoPath  = "") override;

};

#endif // SET_AVATAR_PHOTO_H
