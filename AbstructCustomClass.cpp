#include "AbstructCustomClass.h"

AbstructCustomClass::AbstructCustomClass()
{
    _config=new CustomClass();
}

void AbstructCustomClass::render()
{

}

bool AbstructCustomClass::submit()
{
    return true;
}

void AbstructCustomClass::setconfig(CustomClass* config)
{
    _config=config;
}



