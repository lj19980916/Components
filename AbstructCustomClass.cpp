#include "AbstructCustomClass.h"

AbstructCustomClass::AbstructCustomClass()
{

}

void AbstructCustomClass::render()
{

}

bool AbstructCustomClass::submit()
{
    return true;
}

void AbstructCustomClass::setconfig(CustomClass config)
{
    _config=config;
}

CustomClass AbstructCustomClass::getconfig()
{
    return _config;
}



