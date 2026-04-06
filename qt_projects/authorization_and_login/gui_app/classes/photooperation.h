#ifndef PHOTOOPERATION_H
#define PHOTOOPERATION_H
#include <QString>
class PhotoOperation
{
public:
    PhotoOperation()= default;
    virtual ~PhotoOperation() = default;
    virtual QString execute(QString login, const QString& photoPath  = "") =0;

};
#endif // PHOTOOPERATION_H
