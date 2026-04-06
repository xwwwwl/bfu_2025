#ifndef PHOTO_FILE_HANDLER_H
#define PHOTO_FILE_HANDLER_H
#include <QString>
#include "filehandler.h"
class PhotoFileHandler : public FileHandler
{
public:
    PhotoFileHandler();
    bool CopyPhoto(QString PhotoPath, QString NewPhotoPath);
    bool DeletePhoto(QString PhotoPath);
    bool DeleteAllEmptyFolder(QString PhotoPath);
};

#endif // PHOTO_FILE_HANDLER_H
