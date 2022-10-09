#include "CustomClass.h"

CustomClass::CustomClass()
{

}
DataType CustomClass::getDataType()
{
    return _dataType;
}

void CustomClass::setDataType(DataType dataType)
{
    _dataType=dataType;
}

void CustomClass::setLabel(QString label)
{
    _label=label;
}

QString CustomClass::Label()
{
    return _label;
}

void CustomClass::setComponentType(ComponentType type)
{
    _componentType=type;
}

ComponentType CustomClass::getComponentType()
{
    return _componentType;
}

QString CustomClass::defaultValue()
{
    return _defaultValue;
}

void CustomClass::setDefaultValue(QString defaultValue)
{
    _defaultValue=defaultValue;
}



void CustomClass::setCandidateValue(QString c)
{
    _candidateValue<<c;
}

QList<QString> CustomClass::candidateValue()
{
    return _candidateValue;
}

bool CustomClass::editable()
{
    return _editable;
}

void CustomClass::setEditable(bool editable)
{
    _editable=editable;
}

bool CustomClass::required()
{
    return _required;
}

void CustomClass::setRequired(bool required)
{
    _required=required;
}

QString CustomClass::getValue()
{
    return _Value;
}

void CustomClass::setValue(QString value)
{
    _Value=value;
}
