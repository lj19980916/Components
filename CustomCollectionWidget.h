#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "AbstructCustomClass.h"
#include "ArgumentsClass.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void render();//渲染界面
    // 几个组配置，几个groupBox
    // 每组配置一个groupBox
    // groupBox 垂直布局
    // Form布局
    // lable 列就是 每个配置的label，
    // 第二列就是你的组件

    bool submit();// 提交的时候检测是否必填的都填了，循环遍历
    void setWidgetList(ArgumentsClass c);//把参数组对象传到参数组列表里
    void AddCustomObjList(AbstructCustomClass c);//添加组件到组件列表
private slots:
    void save();
private:
    std::vector<AbstructCustomClass> _customObjList={};//组件列表
    std::vector<ArgumentsClass> _widgetList={};//参数组列表
    QPushButton *button;
};
#endif // WIDGET_H
