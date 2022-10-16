#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <AbstructCustomClass.h>
class CUICheckBoxWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUICheckBoxWidget(QWidget *parent = nullptr);
    void render() override;
    bool submit() override;//提交的时候检测是否必填的都填了
    QList<QCheckBox *> checkbox_list={};//动态创建按钮的列表
signals:

};

#endif // CHECKBOX_H
