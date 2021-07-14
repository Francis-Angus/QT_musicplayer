#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>
#include <QComboBox>
#include <QDebug>
#include <QCOMBOBOX>


class ComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e) override;

signals:
    void clk_comboBox();

public slots:
};

#endif // COMBOBOX_H
