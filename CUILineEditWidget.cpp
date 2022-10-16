#include "CUILineEditWidget.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QLabel>
#include <QToolTip>
#include <QFormLayout>

CUILineEditWidget:: CUILineEditWidget (QWidget *parent) : QWidget(parent)
{

}
void CUILineEditWidget::render()
{
    //setValidator提供了一个确保一个字符串包含一个在一定有效范围内的整数的验证器
    Le_edit->setValidator(new QDoubleValidator(0, 3000, 2));
    connect(Le_edit,&QLineEdit::textEdited,[=](){
        check_correct();
    });
    //接收配置
    CustomClass custom=getconfig();
    //设置配置
    QHBoxLayout *Hlayout=new QHBoxLayout();
    Hlayout->addWidget(Le_edit);
    setLayout(Hlayout);

}
bool CUILineEditWidget::submit()
{
    // 1获取值
    //2 值是否是空的，如果是空的， 进行错误提示 turn_red()，return false;
    //3 值是超过设置的范围，如果超过范围， 进行错误提示 turn_red()，return false;
    //判断候选值是否为空，然后输出候选值
    //判断哪个按钮被选中并输出相应的值
    if(Le_edit->text()==""||Le_edit->text().toDouble() < 0 ||Le_edit->text().toDouble() > 3000)
    {
        turn_red();
        return false;
    }
    else
    {
        // LineEdit恢复之前的状态
        Le_edit->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        qDebug()<<"save_LineEdit"<<Le_edit->text();
        return true;
    }
}
//变红的错误提示
void CUILineEditWidget::turn_red()
{
    QToolTip::showText(Le_edit->mapToGlobal(QPoint(100, 0)),"0-3000");
    // 设置LineEdit变为红色
    Le_edit->setStyleSheet("QLineEdit{border:1px solid red }");
}

void CUILineEditWidget::check_correct()
{
    if(Le_edit->text()==""||Le_edit->text().toDouble() < 0 ||Le_edit->text().toDouble() > 3000)
    {
        turn_red();
    }
    else
    {
        // LineEdit恢复之前的状态
        Le_edit->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
    }
}
