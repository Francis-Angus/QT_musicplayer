#include "combobox.h"

ComboBox::ComboBox(QWidget *parent) : QComboBox(parent)
{

}

void ComboBox::mousePressEvent(QMouseEvent *e)
{
    emit clk_comboBox();
}
