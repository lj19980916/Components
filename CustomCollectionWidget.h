#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include "AbstructCustomClass.h"
#include "ArgumentsClass.h"
#include "CUIRadioButtonWidget.h"
#include "CUICheckBoxWidget.h"
#include "CUIComboBoxWidget.h"
#include "CUILineEditWidget.h"
class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void render();
    bool submit();// 提交的时候检测是否必填的都填了，循环遍历
    void setWidgetList(ArgumentsClass c);//把参数组对象传到参数组列表里
    void AddCustomObjList(AbstructCustomClass* c);//添加组件到组件列表
    QString GroupboxStyle();
    void initGroupBox(QGroupBox *groupbox,ArgumentsClass argument,QFormLayout* FormLayout);
    void initCustom(CustomClass custom,QFormLayout* FormLayout);
    void initButton(QVBoxLayout* VBoxLayout);
private slots:
    void save();
private:
    std::vector<AbstructCustomClass*> _customObjList={};//组件列表
    std::vector<ArgumentsClass> _widgetList={};//参数组列表
    QPushButton *button;
};
#endif // WIDGET_H
