#include "CUICheckBoxWidget.h"

#include <QVBoxLayout>
#include <QDebug>
CUICheckBoxWidget::CUICheckBoxWidget(QWidget *parent) : QWidget(parent)
{

}
void CUICheckBoxWidget::render()
{
    //接收配置
       CustomClass custom=getconfig();
       QCheckBox *check_box;//动态创建按钮指针
       QHBoxLayout *Hlayout=new QHBoxLayout();
       int total=custom.candidateValue().size();
       for(int i=0;i<total;i++)
       {
           check_box=new QCheckBox;
           //设置按钮对象名字
           check_box->setText(custom.candidateValue().at(i));
           if(custom.defaultValue()==custom.candidateValue().at(i))
               check_box->setChecked(true);
           //把按钮添加到按钮列表中
           checkbox_list.append(check_box);
           //设置按钮的水平布局
           Hlayout->addWidget(check_box);
       }
       setLayout(Hlayout);
       this->layout()->setContentsMargins(0,0,0,0);
}

bool CUICheckBoxWidget::submit()
{
    //判断哪个按钮被选中并输出相应的值
    for(int i=0;i<checkbox_list.size();i++){
        //如果按钮被选中
        if(checkbox_list.at(i)->isChecked()){
            qDebug()<<"save_radiobutton"<<i;
            return true;

        }
    }
    qDebug()<<"radiobutton_kong";
    return false;
}
