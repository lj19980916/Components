#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "AbstructCustomClass.h"
#include <QComboBox>
#include <QWidget>

class CUIComboBoxWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUIComboBoxWidget(QWidget *parent = nullptr);
    void render() override;
    bool submit() override;
private:
    QStringList strList;
    QComboBox *combox=new QComboBox();

signals:

};

#endif // COMBOBOX_H
