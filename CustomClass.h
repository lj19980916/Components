#ifndef CUSTOMCLASS_H
#define CUSTOMCLASS_H

#include <QList>
enum ComponentType
{
    RadioButton,
    CheckBox,
    LineEdit,
    ComboBox
};

enum DataType {
    IntType,
    DoubleType,
    QStringType,
    BoolType,
};
class CustomClass
{
public:
    CustomClass();
public:
    DataType getDataType();
    void setDataType(DataType dataType);
    void setLabel(QString label);//设置标题名字
    QString Label();//获取标题名字
    void setComponentType(ComponentType type);//设置组件的类型
    ComponentType getComponentType();//获取组件的类型
    QString defaultValue();//获取组件的初始值
    void setDefaultValue(QString defaultValue);//设置组件的初始值
    int IntDefaultValue();//获取组件的int初始值
    void setIntDefaultValue(int IntDefaultValue);//设置组件的int初始值
    bool BoolDefaultValue();//获取组件的bool初始值
    void setBoolDefaultValue(bool BoolDefaultValue);//设置组件的bool初始值
    double DoubleDefaultValue();//获取组件的double初始值
    void setDoubleDefaultValue(double DoubleDefaultValue);//设置组件的double初始值

    void setCandidateValue(QString c);
    QList<QString> candidateValue();//获取候选值列表
    void setIntCandidateValue(int c);
    QList<int> IntCandidateValue();//获取int候选值列表
    void setBoolCandidateValue(bool c);
    QList<bool> BoolCandidateValue();//获取bool候选值列表
    void setDoubleCandidateValue(double c);
    QList<double> DoubleCandidateValue();//获取double候选值列表

    bool editable();//获取组件是否可以编辑
    void setEditable(bool editable);//设置组件是否可以编辑
    bool required();//获取组件是否必填
    void setRequired(bool required);//设置组件是否必填

    QString getValue();
    void setValue(QString value);
    int getIntValue();
    void setIntValue(int value);
    bool getBoolValue();
    void setBoolValue(bool value);
    double getDoubleValue();
    void setDoubleValue(double value);

    void setCustomConfig(DataType dataType,QString label,ComponentType type,QString defaultValue,bool required,QString value);
    void setCustomConfig(DataType dataType,QString label,ComponentType type,int defaultValue,bool required,int value);
    void setCustomConfig(DataType dataType,QString label,ComponentType type,bool defaultValue,bool required,bool value);
    void setCustomConfig(DataType dataType,QString label,ComponentType type,double defaultValue,bool required,double value);
private:
    DataType _dataType;//参数的数据类型
    QString _label;//每一行的标题
    ComponentType _componentType;//组件类型
    QString _defaultValue;//初始值
    QList<QString> _candidateValue={};//候选值
    int _IntDefaultValue;//int型初始值
    QList<int> _IntCandidateValue={};//int 候选值
    bool _BoolDefaultValue;//bool初始值
    QList<bool> _BoolCandidateValue={};//bool候选值
    double _DoubleDefaultValue;//double初始值
    QList<double> _DoubleCandidateValue={};//double候选值
    bool _editable;//是否可以编辑
    bool _required;//是否为必填
    QString _Value;//值引用
    int _IntValue;//int 值
    bool _BoolValue;//bool值
    double _DoubleValue;//double值
};

#endif // CUSTOMCLASS_H
