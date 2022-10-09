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
    void setCandidateValue(QString c);
    QList<QString> candidateValue();//获取候选值列表
    bool editable();//获取组件是否可以编辑
    void setEditable(bool editable);//设置组件是否可以编辑
    bool required();//获取组件是否必填
    void setRequired(bool required);//设置组件是否必填
    QString getValue();
    void setValue(QString value);
private:
    DataType _dataType;//参数的数据类型
    QString _label;//每一行的标题
    ComponentType _componentType;//组件类型
    QString _defaultValue;//初始值
    QList<QString> _candidateValue={};//候选值
    bool _editable;//是否可以编辑
    bool _required;//是否为必填
    QString _Value;//值引用
};

#endif // CUSTOMCLASS_H
