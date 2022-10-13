#include "CUIRadioButtonWidget.h"

#include <QButtonGroup>
#include <QFormLayout>

CUIRadioButtonWidget::CUIRadioButtonWidget(QWidget *parent) : QWidget(parent)
{

}

void CUIRadioButtonWidget::render()
{
    //接收配置
       CustomClass custom=getconfig();
       QRadioButton *btnRadio;//动态创建按钮指针
       QHBoxLayout *Hlayout=new QHBoxLayout();
       int total=custom.candidateValue().size();
       for(int i=0;i<total;i++)
       {
           btnRadio=new QRadioButton;
           //设置按钮对象名字
           btnRadio->setText(custom.candidateValue().at(i));
           if(custom.defaultValue()==custom.candidateValue().at(i))
               btnRadio->setChecked(true);
           //把按钮添加到按钮列表中
           btnRadiolist.append(btnRadio);
           //把按钮添加到组中
           //block1->addButton(btnRadio,i);
           //设置按钮的水平布局
           Hlayout->addWidget(btnRadio);
       }
       setLayout(Hlayout);
       //this->layout()->contentsMargins();
       this->layout()->setContentsMargins(0,0,0,0);
}


bool CUIRadioButtonWidget::submit()
{
    return true;
}
