#include "CustomCollectionWidget.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QSpacerItem>
#include <QComboBox>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ArgumentsClass argument1;//第一个groupbox
    argument1.setGroupName("");
    CustomClass custom1;
    QList<QString> candidateValueList1={};
    candidateValueList1<<tr("是")<<tr("否");
    for (int i=0;i<candidateValueList1.size();i++) {
        custom1.setCandidateValue(candidateValueList1.at(i));
    }
    custom1.setEditable(true);
    custom1.setCustomConfig(DataType::QStringType,tr("非定常"),ComponentType::RadioButton,tr("是"),true,tr("是"));
    argument1.AddArgument(custom1);
    setWidgetList(argument1);

    ArgumentsClass argument2;//第二个groupbox
    argument2.setGroupName(tr("模型"));
    CustomClass custom2;
    QList<QString> candidateValueList2={};
    candidateValueList2<<tr("层流")<<tr("湍流");
    for (int i=0;i<candidateValueList2.size();i++) {
        custom2.setCandidateValue(candidateValueList2.at(i));
    }
    custom2.setEditable(true);
    custom2.setCustomConfig(DataType::QStringType,tr("流体模型"),ComponentType::RadioButton,tr("湍流"),true,tr("湍流"));
    argument2.AddArgument(custom2);
    CustomClass custom3;
    QList<QString> candidateValueList3={};
    candidateValueList3<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList3.size();i++) {
        custom3.setCandidateValue(candidateValueList3.at(i));
    }
    custom3.setEditable(true);
    custom3.setCustomConfig(DataType::QStringType,tr("能量方程"),ComponentType::RadioButton,tr("不开启"),true,tr("不开启"));
    argument2.AddArgument(custom3);
    CustomClass custom4;
    QList<QString> candidateValueList4={};
    candidateValueList4<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList4.size();i++) {
        custom4.setCandidateValue(candidateValueList4.at(i));
    }
    custom4.setEditable(true);
    custom4.setCustomConfig(DataType::QStringType,tr("粘性更新"),ComponentType::RadioButton,tr("开启"),true,tr("开启"));
    argument2.AddArgument(custom4);
    CustomClass custom5;
    QList<QString> candidateValueList5={};
    candidateValueList5<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList5.size();i++) {
        custom5.setCandidateValue(candidateValueList5.at(i));
    }
    custom5.setEditable(true);
    custom5.setCustomConfig(DataType::QStringType,tr("多相流"),ComponentType::RadioButton,tr("不开启"),true,tr("不开启"));
    argument2.AddArgument(custom5);
    setWidgetList(argument2);
    ArgumentsClass argument3;//第三个groupbox
    argument3.setGroupName(tr(""));
    CustomClass custom6;
    QList<QString> candidateValueList6={};
    candidateValueList6<<tr("开启")<<tr("不开启");
    for (int i=0;i<candidateValueList6.size();i++) {
        custom6.setCandidateValue(candidateValueList6.at(i));
    }
    custom6.setEditable(true);
    custom6.setCustomConfig(DataType::QStringType,tr("高级设置"),ComponentType::RadioButton,tr("不开启"),true,tr("不开启"));
    argument3.AddArgument(custom6);
    setWidgetList(argument3);
    ArgumentsClass argument4;//第四个groupbox
    argument4.setGroupName(tr("湍流"));
    CustomClass custom7;
    QList<QString> candidateValueList7={};
    candidateValueList7<<tr("k-e");
    for (int i=0;i<candidateValueList7.size();i++) {
        custom7.setCandidateValue(candidateValueList7.at(i));
    }
    custom7.setEditable(true);
    custom7.setCustomConfig(DataType::QStringType,tr("湍流模型"),ComponentType::ComboBox,tr("k-e"),true,tr("k-e"));
    argument4.AddArgument(custom7);
    setWidgetList(argument4);
    setGeometry(0,0,430,800);
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
    for (int i =0;i<_widgetList.size();i++) {
        QFormLayout* FormLayout = new QFormLayout();//设置Form布局
        ArgumentsClass argument=_widgetList.at(i);
        QGroupBox *groupbox=new QGroupBox();
        initGroupBox(groupbox,argument,FormLayout);//初始化groupbox
        std::vector<CustomClass> argumentList=argument.getArgument();
        for (int j=0;j<argumentList.size();j++) {
            CustomClass custom=argumentList.at(j);//参数对象列表
            initCustom(custom,FormLayout);//初始化参数列表
        }
        VBoxLayout->addWidget(groupbox);
    }
    VBoxLayout->addStretch();
    initButton(VBoxLayout);//初始化按钮布局
    setLayout(VBoxLayout);

}

bool Widget::submit()
{
//    int flag=true;
//        for(int i=0;i<_customObjList.size;i++)
//        {
//            if(!_customObjList.at(i).submit()){
//                return false;
//            }
//        }
//        return true;
    return true;
}

void Widget::setWidgetList(ArgumentsClass c)
{
    _widgetList.push_back(c);
}

void Widget::AddCustomObjList(AbstructCustomClass* c)
{
    _customObjList.push_back(c);
}

QString Widget::GroupboxStyle()
{
    QString style="QGroupBox"
                  "{"
                  "margin-top:20px;"
                  "}"
                  "QGroupBox:title"
                  "{"
                  "subcontrol-origin: margin;"
                  "subcontrol-position: top left;"
                  "left: -6px;"
                  "padding:0 1px;"
                  "}";
    return style;
}

void Widget::initGroupBox(QGroupBox *groupbox,ArgumentsClass argument, QFormLayout *FormLayout)
{
    groupbox->setTitle(argument.getGroupName());
    groupbox->setLayout(FormLayout);
    groupbox->setStyleSheet(GroupboxStyle());
    QSizePolicy GroupBoxSizePolicy = groupbox->sizePolicy();
    GroupBoxSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    GroupBoxSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    groupbox->setSizePolicy(GroupBoxSizePolicy);
    if(argument.getGroupName()=="")
    {
        groupbox->setStyleSheet("QGroupBox {border:none}");
    }
}

void Widget::initCustom(CustomClass custom,QFormLayout* FormLayout)
{
    QLabel *labeltitle=new QLabel(custom.Label());
    labeltitle->setFixedWidth(200);
    switch (custom.getComponentType())
    {
    case RadioButton:
    {
        CUIRadioButtonWidget *radiobutton=new CUIRadioButtonWidget();
        AddCustomObjList(radiobutton);
        radiobutton->setconfig(custom);
        radiobutton->render();
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

void Widget::initButton(QVBoxLayout* VBoxLayout)
{
    button->setText(tr("保存"));
    QSizePolicy buttonSizePolicy = button->sizePolicy();
    buttonSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    buttonSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    button->setSizePolicy(buttonSizePolicy);
    QHBoxLayout* HBoxLayout = new QHBoxLayout();
    HBoxLayout->addStretch(1);
    HBoxLayout->addWidget(button,0,Qt::AlignHCenter);
    HBoxLayout->addStretch(1);
    QWidget *widget=new QWidget();
    widget->setLayout(HBoxLayout);
    VBoxLayout->addWidget(widget);
}

void Widget::save()
{
    if(submit())
    {
        qDebug()<<"123";
    }
}

