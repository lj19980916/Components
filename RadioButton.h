#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QRadioButton>
#include <QWidget>
#include "AbstructCustomClass.h"
class RadioButton : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit RadioButton(QWidget *parent = nullptr);
public:
    void render() override;
    bool submit() override;//提交的时候检测是否必填的都填了
    QList<QRadioButton*> btnRadiolis={};//动态创建按钮的列表
    int total=0;
signals:

};

#endif // RADIOBUTTON_H
