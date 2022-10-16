#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include <QWidget>
#include "AbstructCustomClass.h"
class CUILineEditWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUILineEditWidget(QWidget *parent = nullptr);
    void render() override;
    bool submit() override;
    void turn_red();
    void check_correct();
private:
    QLineEdit *Le_edit=new QLineEdit();
signals:

};

#endif // LINEEDIT_H
