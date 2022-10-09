#include "ArgumentsClass.h"

ArgumentsClass::ArgumentsClass()
{

}
QString ArgumentsClass::getGroupName()
{
    return _groupName;
}

void ArgumentsClass::setGroupName(QString groupName)
{
    _groupName=groupName;
}

void ArgumentsClass::AddArgument(CustomClass argument)
{
    _argumentList.push_back(argument);
}

std::vector<CustomClass> ArgumentsClass::getArgument()
{
    return _argumentList;
}
