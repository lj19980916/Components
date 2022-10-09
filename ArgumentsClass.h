#ifndef ARGUMENTSCLASS_H
#define ARGUMENTSCLASS_H

#include <QObject>
#include "CustomClass.h"
class ArgumentsClass
{
public:
    ArgumentsClass();
public:
    QString getGroupName();//获取groupbox的名字
    void setGroupName(QString groupName);//设置groupbox的名字
    void AddArgument(CustomClass argument);//添加参数对象到列表中
    std::vector<CustomClass> getArgument();
private:
    QString _groupName;//每一个groupbox的名字
    std::vector<CustomClass> _argumentList={};//参数对象列表
};

#endif // ARGUMENTSCLASS_H
