#ifndef DELETE_PHOTO_H
#define DELETE_PHOTO_H
#include "photooperation.h"

class DeletePhoto: public PhotoOperation
{
public:
    DeletePhoto() = default;
    QString execute(User* user, const QString& photoPath  = "") override;

};

#endif // DELETE_PHOTO_H
