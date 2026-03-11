#ifndef USER_FILE_HANDLER_H
#define USER_FILE_HANDLER_H
#include "filehandler.h"

class UserFileHandler : public FileHandler
{
private:
    User user_;
public:
    UserFileHandler(User user);
    QString get_path_to_user_avatar();
    QVector<QString> get_vector_to_user_photo();


};

#endif // USER_FILE_HANDLER_H
