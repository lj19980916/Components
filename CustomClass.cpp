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

int CustomClass::IntDefaultValue()
{
    return _IntDefaultValue;
}

void CustomClass::setIntDefaultValue(int IntDefaultValue)
{
    _IntDefaultValue=IntDefaultValue;
}

bool CustomClass::BoolDefaultValue()
{
    return _BoolDefaultValue;
}

void CustomClass::setBoolDefaultValue(bool BoolDefaultValue)
{
    _BoolDefaultValue=BoolDefaultValue;
}

double CustomClass::DoubleDefaultValue()
{
    return _DoubleDefaultValue;
}

void CustomClass::setDoubleDefaultValue(double DoubleDefaultValue)
{
    _DoubleDefaultValue=DoubleDefaultValue;
}



void CustomClass::setCandidateValue(QString c)
{
    _candidateValue<<c;
}

QList<QString> CustomClass::candidateValue()
{
    return _candidateValue;
}

void CustomClass::setIntCandidateValue(int c)
{
    _IntCandidateValue<<c;
}

QList<int> CustomClass::IntCandidateValue()
{
    return _IntCandidateValue;
}

void CustomClass::setBoolCandidateValue(bool c)
{
    _BoolCandidateValue<<c;
}

QList<bool> CustomClass::BoolCandidateValue()
{
    return _BoolCandidateValue;
}

void CustomClass::setDoubleCandidateValue(double c)
{
    _DoubleCandidateValue<<c;
}

QList<double> CustomClass::DoubleCandidateValue()
{
    return _DoubleCandidateValue;
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

int CustomClass::getIntValue()
{
    return _IntValue;
}

void CustomClass::setIntValue(int value)
{
    _IntValue=value;
}

bool CustomClass::getBoolValue()
{
    return _IntValue;
}

void CustomClass::setBoolValue(bool value)
{
    _BoolValue=value;
}

double CustomClass::getDoubleValue()
{
    return _DoubleValue;
}

void CustomClass::setDoubleValue(double value)
{
    _DoubleValue=value;
}

void CustomClass::setCustomConfig(DataType dataType, QString label, ComponentType type, QString defaultValue, bool required, QString value)
{
    _dataType=dataType;
    _label=label;
    _componentType=type;
    _defaultValue=defaultValue;
    _required=required;
    _Value=value;
}

void CustomClass::setCustomConfig(DataType dataType, QString label, ComponentType type, int defaultValue, bool required, int value)
{
    _dataType=dataType;
    _label=label;
    _componentType=type;
    _IntDefaultValue=defaultValue;
    _required=required;
    _IntValue=value;
}

void CustomClass::setCustomConfig(DataType dataType, QString label, ComponentType type, bool defaultValue, bool required, bool value)
{
    _dataType=dataType;
    _label=label;
    _componentType=type;
    _BoolDefaultValue=defaultValue;
    _required=required;
    _BoolValue=value;
}

void CustomClass::setCustomConfig(DataType dataType, QString label, ComponentType type, double defaultValue, bool required, double value)
{
    _dataType=dataType;
    _label=label;
    _componentType=type;
    _DoubleDefaultValue=defaultValue;
    _required=required;
    _DoubleValue=value;
}
