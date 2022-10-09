#include "CustomCollectionWidget.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QSpacerItem>
#include <QComboBox>
#include "RadioButton.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ArgumentsClass argument1;//第一个groupbox
    argument1.setGroupName("");
    CustomClass custom1;
    custom1.setDataType(DataType::QStringType);
    custom1.setLabel(tr("非定常"));
    custom1.setComponentType(ComponentType::RadioButton);
    custom1.setDefaultValue(tr("是"));
    QList<QString> candidateValueList1={};
    candidateValueList1<<tr("是")<<tr("否");
    for (int i=0;i<candidateValueList1.size();i++) {
        custom1.setCandidateValue(candidateValueList1.at(i));
    }
    custom1.setEditable(true);
    custom1.setRequired(true);
    custom1.setValue(tr("是"));
    argument1.AddArgument(custom1);
    setWidgetList(argument1);

    ArgumentsClass argument2;//第二个groupbox
    argument2.setGroupName(tr("模型"));
    CustomClass custom2;
    custom2.setDataType(DataType::QStringType);
    custom2.setLabel(tr("流体模型"));
    custom2.setComponentType(ComponentType::RadioButton);
    custom2.setDefaultValue(tr("湍流"));
    QList<QString> candidateValueList2={};
    candidateValueList2<<tr("层流")<<tr("湍流");
    for (int i=0;i<candidateValueList2.size();i++) {
        custom2.setCandidateValue(candidateValueList2.at(i));
    }
    custom2.setEditable(true);
    custom2.setRequired(true);
    custom2.setValue(tr("湍流"));
    argument2.AddArgument(custom2);
    CustomClass custom3;
    custom3.setDataType(DataType::QStringType);
    custom3.setLabel(tr("能量方程"));
    custom3.setComponentType(ComponentType::RadioButton);
    custom3.setDefaultValue(tr("不开启"));
    QList<QString> candidateValueList3={};
    candidateValueList3<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList3.size();i++) {
        custom3.setCandidateValue(candidateValueList3.at(i));
    }
    custom3.setEditable(true);
    custom3.setRequired(true);
    custom3.setValue(tr("不开启"));
    argument2.AddArgument(custom3);
    CustomClass custom4;
    custom4.setDataType(DataType::QStringType);
    custom4.setLabel(tr("粘性更新"));
    custom4.setComponentType(ComponentType::RadioButton);
    custom4.setDefaultValue(tr("开启"));
    QList<QString> candidateValueList4={};
    candidateValueList4<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList4.size();i++) {
        custom4.setCandidateValue(candidateValueList4.at(i));
    }
    custom4.setEditable(true);
    custom4.setRequired(true);
    custom4.setValue(tr("开启"));
    argument2.AddArgument(custom4);
    CustomClass custom5;
    custom5.setDataType(DataType::QStringType);
    custom5.setLabel(tr("多相流"));
    custom5.setComponentType(ComponentType::RadioButton);
    custom5.setDefaultValue(tr("不开启"));
    QList<QString> candidateValueList5={};
    candidateValueList5<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList5.size();i++) {
        custom5.setCandidateValue(candidateValueList5.at(i));
    }
    custom5.setEditable(true);
    custom5.setRequired(true);
    custom5.setValue(tr("不开启"));
    argument2.AddArgument(custom5);
    setWidgetList(argument2);
    ArgumentsClass argument3;//第三个groupbox
    argument3.setGroupName(tr(""));
    CustomClass custom6;
    custom6.setDataType(DataType::QStringType);
    custom6.setLabel(tr("高级设置"));
    custom6.setComponentType(ComponentType::RadioButton);
    custom6.setDefaultValue(tr("不开启"));
    QList<QString> candidateValueList6={};
    candidateValueList6<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList6.size();i++) {
        custom6.setCandidateValue(candidateValueList6.at(i));
    }
    custom6.setEditable(true);
    custom6.setRequired(true);
    custom6.setValue(tr("不开启"));
    argument3.AddArgument(custom6);
    setWidgetList(argument3);
    ArgumentsClass argument4;//第四个groupbox
    argument4.setGroupName(tr("湍流"));
    CustomClass custom7;
    custom7.setDataType(DataType::QStringType);
    custom7.setLabel(tr("湍流模型"));
    custom7.setComponentType(ComponentType::ComboBox);
    custom7.setDefaultValue(tr("k-e"));
    QList<QString> candidateValueList7={};
    candidateValueList7<<tr("k-e");
    for (int i=0;i<candidateValueList7.size();i++) {
        custom7.setCandidateValue(candidateValueList7.at(i));
    }
    custom7.setEditable(true);
    custom7.setRequired(true);
    custom7.setValue(tr("k-e"));
    argument4.AddArgument(custom7);
    setWidgetList(argument4);
    setGeometry(0,0,511,1006);
    button=new QPushButton;
    connect(button,&QPushButton::clicked,this,&Widget::save);
    render();

}

Widget::~Widget()
{
}

void Widget::render()
{
    QVBoxLayout* VBoxLayout = new QVBoxLayout();//设置垂直布局
    QHBoxLayout* HBoxLayout = new QHBoxLayout();
    for (int i =0;i<_widgetList.size();i++) {
        QFormLayout* FormLayout = new QFormLayout();//设置Form布局
        ArgumentsClass argument=_widgetList.at(i);
        QGroupBox *groupbox=new QGroupBox(tr(""));
        groupbox->setLayout(FormLayout);
        QLabel *title=new QLabel(argument.getGroupName());
        QSizePolicy labelSizePolicy = title->sizePolicy();
        labelSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
        labelSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
        title->setSizePolicy(labelSizePolicy);
        QSizePolicy GroupBoxSizePolicy = groupbox->sizePolicy();
        GroupBoxSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
        GroupBoxSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
        groupbox->setSizePolicy(GroupBoxSizePolicy);
        if(argument.getGroupName()=="")
        {
            groupbox->setStyleSheet("QGroupBox {border:none}");
        }
        std::vector<CustomClass> argumentList=argument.getArgument();
        for (int j=0;j<argumentList.size();j++) {
            CustomClass custom=argumentList.at(j);
            QLabel *labeltitle=new QLabel(custom.Label());
            labeltitle->setFixedWidth(200);
            switch (custom.getComponentType())
            {
            case RadioButton:
            {
//                RadioButton *radioButton=new RadioButton();
//                AddCustomObjList(radioButton);
//                radioButton.setconfig(_widgetList.at(i).getArgument().at(j));
//                radioButton.render();
//                AddCustomObjList()
                QRadioButton *radiobutton=new QRadioButton(custom.defaultValue());
                FormLayout->addRow(labeltitle,radiobutton);
                break;
            }
            case CheckBox:
            {
                break;
            }
            case LineEdit:
            {
                break;
            }
            case ComboBox:
            {
                QComboBox *combox=new QComboBox;
                for (int i=0;i<custom.candidateValue().size();i++) {
                    combox->addItem(custom.candidateValue().at(i));
                }
                FormLayout->addRow(labeltitle,combox);
                break;
            }
            }
        }
        if(argument.getGroupName()!="")
        {
            VBoxLayout->addWidget(title);
        }
        VBoxLayout->addWidget(groupbox);
    }
    VBoxLayout->addStretch();
    button->setText(tr("保存"));
    QSizePolicy buttonSizePolicy = button->sizePolicy();
    buttonSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    buttonSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    button->setSizePolicy(buttonSizePolicy);

    HBoxLayout->addStretch(1);
    HBoxLayout->addWidget(button,0,Qt::AlignHCenter);
    HBoxLayout->addStretch(1);
    QWidget *widget=new QWidget();
    widget->setLayout(HBoxLayout);
    VBoxLayout->addWidget(widget);
    setLayout(VBoxLayout);

}

bool Widget::submit()
{
//    int flag=true;
//        for(int i=0;i<_customObjList.size;i++)
//        {
//            if(!_customObjList.at(i).submit()){
//                flag =false;
//            }
//        }
//        return flag;
    return true;
}

void Widget::setWidgetList(ArgumentsClass c)
{
    _widgetList.push_back(c);
}

void Widget::AddCustomObjList(AbstructCustomClass c)
{
    _customObjList.push_back(c);
}

void Widget::save()
{
    if(submit())
    {
        qDebug()<<"123";
    }
}

