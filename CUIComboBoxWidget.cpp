#include "CUIComboBoxWidget.h"
#include <QWidget>
#include <QDebug>
#include <QFormLayout>

CUIComboBoxWidget::CUIComboBoxWidget(QWidget *parent) : QWidget(parent)
{

}

void CUIComboBoxWidget::render()
{
    //接收配置
    CustomClass custom=getconfig();
    QHBoxLayout *Hlayout=new QHBoxLayout();

    //接收一个有候选值的数组。候选值应该在数组中，for循环取值。
    for (int i=0;i<custom.candidateValue().size();i++) {
        combox->addItem(custom.candidateValue().at(i));
    }
    Hlayout->addWidget(combox);
    setLayout(Hlayout);
    this->layout()->setContentsMargins(0,0,0,0);
}

bool CUIComboBoxWidget::submit()
{
    //   判断候选值是否为空，然后输出候选值
    //   判断哪个按钮被选中并输出相应的值
    //    for(int i=1;i<custom.candidateValue().size();i++){
    //        //如果按钮被选中
    //        if(combox->currentText()==strList.at(i)){
    //            qDebug()<<"combox_BaoCun"<<combox->currentText();
    //            return true;
    //        }
    //    }
    qDebug()<<"combox_kong";
    return false;
}
