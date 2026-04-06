#ifndef SET_AVATAR_PHOTO_H
#define SET_AVATAR_PHOTO_H
#include "photooperation.h"

class SetAvatarPhoto: public PhotoOperation
{
public:
    SetAvatarPhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};

#endif // SET_AVATAR_PHOTO_H
