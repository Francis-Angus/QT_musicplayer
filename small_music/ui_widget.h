/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lyrics_lab;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QLabel *song_name_lab;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *add_file_btn;
    QToolButton *delete_file_btn;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *song_file_combobox;
    QSpacerItem *horizontalSpacer;
    QToolButton *previous_btn;
    QToolButton *play_pause_btn;
    QToolButton *next_btn;
    QSpacerItem *horizontalSpacer_5;
    QLabel *current_time_lab;
    QLabel *label_2;
    QLabel *total_time_lab;
    QToolButton *voice_btn;
    QSlider *voice_slider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(861, 165);
        Widget->setMaximumSize(QSize(863, 16777215));
        Widget->setStyleSheet(QLatin1String("\n"
"\n"
"QWidget\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(85, 85, 85, 241), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #ffffff;\n"
"	font-weight: bold;\n"
"	border-color: #051a39;\n"
"	selection-background-color: #3b7e48;\n"
"\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_7 = new QWidget(Widget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setStyleSheet(QStringLiteral("background-color: transparent;"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        lyrics_lab = new QLabel(widget_9);
        lyrics_lab->setObjectName(QStringLiteral("lyrics_lab"));
        QFont font;
        font.setPointSize(21);
        font.setBold(true);
        font.setWeight(75);
        lyrics_lab->setFont(font);
        lyrics_lab->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}"));

        horizontalLayout_7->addWidget(lyrics_lab);

        horizontalSpacer_4 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_9);

        line = new QFrame(widget_7);
        line->setObjectName(QStringLiteral("line"));
        line->setMaximumSize(QSize(803, 16777215));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        song_name_lab = new QLabel(widget_7);
        song_name_lab->setObjectName(QStringLiteral("song_name_lab"));
        song_name_lab->setMinimumSize(QSize(817, 22));
        song_name_lab->setMaximumSize(QSize(800, 60));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        song_name_lab->setFont(font1);
        song_name_lab->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}"));

        verticalLayout->addWidget(song_name_lab);

        widget_5 = new QWidget(widget_7);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(800, 35));
        widget_5->setMaximumSize(QSize(800, 150));
        widget_5->setStyleSheet(QStringLiteral("background-color: transparent;"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        add_file_btn = new QToolButton(widget_5);
        add_file_btn->setObjectName(QStringLiteral("add_file_btn"));
        add_file_btn->setMaximumSize(QSize(40, 40));
        add_file_btn->setStyleSheet(QLatin1String("QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/add-folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_file_btn->setIcon(icon);
        add_file_btn->setIconSize(QSize(50, 50));
        add_file_btn->setAutoRaise(true);
        add_file_btn->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(add_file_btn);

        delete_file_btn = new QToolButton(widget_5);
        delete_file_btn->setObjectName(QStringLiteral("delete_file_btn"));
        delete_file_btn->setMaximumSize(QSize(40, 40));
        delete_file_btn->setStyleSheet(QLatin1String("QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/delete-folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_file_btn->setIcon(icon1);
        delete_file_btn->setIconSize(QSize(60, 60));
        delete_file_btn->setCheckable(true);
        delete_file_btn->setPopupMode(QToolButton::DelayedPopup);
        delete_file_btn->setAutoRaise(true);

        horizontalLayout_4->addWidget(delete_file_btn);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        song_file_combobox = new QComboBox(widget_5);
        song_file_combobox->setObjectName(QStringLiteral("song_file_combobox"));
        song_file_combobox->setMinimumSize(QSize(128, 22));
        song_file_combobox->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"    background-color:rgb(255, 255, 255);\n"
"    border: 1px solid;\n"
"    padding-left: 6px;\n"
"    color: #000;\n"
"    height: 20px;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-color: #051a39;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    background-color: #f6f6f6;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    background-color: #f8f6f0;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    background-color: #383838;\n"
"    color: #ffffff;\n"
"    border: 1px solid black;\n"
"    selection-background-color: #488f44;\n"
"    selection-color: #ffffff;\n"
"    outline: 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	background-color: #383838;	\n"
"    image: url(://arrow-down.png) 16px 16px;\n"
"    width: 18px;\n"
"    height: 18p"
                        "x;\n"
"	border-left: 1px solid black;\n"
"\n"
"}"));
        song_file_combobox->setFrame(true);

        horizontalLayout_4->addWidget(song_file_combobox);

        horizontalSpacer = new QSpacerItem(33, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        previous_btn = new QToolButton(widget_5);
        previous_btn->setObjectName(QStringLiteral("previous_btn"));
        previous_btn->setMaximumSize(QSize(50, 50));
        previous_btn->setStyleSheet(QLatin1String("QToolButton:hover{background-color:transparent;}\n"
"QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previous_btn->setIcon(icon2);
        previous_btn->setIconSize(QSize(100, 100));
        previous_btn->setAutoRaise(true);

        horizontalLayout_4->addWidget(previous_btn);

        play_pause_btn = new QToolButton(widget_5);
        play_pause_btn->setObjectName(QStringLiteral("play_pause_btn"));
        play_pause_btn->setMaximumSize(QSize(50, 50));
        play_pause_btn->setStyleSheet(QLatin1String("QToolButton:hover{background-color:transparent;}\n"
"QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        play_pause_btn->setIcon(icon3);
        play_pause_btn->setIconSize(QSize(100, 100));
        play_pause_btn->setAutoRaise(true);

        horizontalLayout_4->addWidget(play_pause_btn);

        next_btn = new QToolButton(widget_5);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setMaximumSize(QSize(50, 50));
        next_btn->setStyleSheet(QLatin1String("QToolButton:hover{background-color:transparent;}\n"
"QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next_btn->setIcon(icon4);
        next_btn->setIconSize(QSize(100, 100));
        next_btn->setAutoRaise(true);

        horizontalLayout_4->addWidget(next_btn);

        horizontalSpacer_5 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        current_time_lab = new QLabel(widget_5);
        current_time_lab->setObjectName(QStringLiteral("current_time_lab"));
        current_time_lab->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}"));

        horizontalLayout_4->addWidget(current_time_lab);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}"));

        horizontalLayout_4->addWidget(label_2);

        total_time_lab = new QLabel(widget_5);
        total_time_lab->setObjectName(QStringLiteral("total_time_lab"));
        total_time_lab->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}"));

        horizontalLayout_4->addWidget(total_time_lab);

        voice_btn = new QToolButton(widget_5);
        voice_btn->setObjectName(QStringLiteral("voice_btn"));
        voice_btn->setMinimumSize(QSize(57, 36));
        voice_btn->setStyleSheet(QLatin1String("QCalendarWidget QToolButton\n"
"{\n"
"  	background-color: transparent;\n"
"  	color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton::hover\n"
"{\n"
"	background-color: #006666;\n"
"	border: 1px solid #006666;\n"
"	color: #fff;\n"
"\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/small_sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        voice_btn->setIcon(icon5);
        voice_btn->setIconSize(QSize(40, 40));
        voice_btn->setAutoRaise(true);

        horizontalLayout_4->addWidget(voice_btn);

        voice_slider = new QSlider(widget_5);
        voice_slider->setObjectName(QStringLiteral("voice_slider"));
        voice_slider->setMinimumSize(QSize(39, 9));
        voice_slider->setMaximumSize(QSize(79, 16777215));
        voice_slider->setStyleSheet(QLatin1String(" QSlider::handle:horizontal{ \n"
"\n"
"		width:  5px; \n"
"		height: 50px; \n"
"		margin-top: -20px; \n"
"		margin-left: 0px; \n"
"		margin-bottom: -20px; \n"
"		margin-right: 0px; \n"
" 		\n"
"	background-color: rgb(80, 80, 80);\n"
"} \n"
""));
        voice_slider->setMaximum(100);
        voice_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(voice_slider);


        verticalLayout->addWidget(widget_5);


        horizontalLayout_2->addWidget(widget_7);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        lyrics_lab->setText(QApplication::translate("Widget", "\346\262\222\346\234\211\346\255\214\350\251\236", Q_NULLPTR));
        song_name_lab->setText(QApplication::translate("Widget", "\346\255\214\345\220\215", Q_NULLPTR));
        add_file_btn->setText(QString());
        delete_file_btn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
        song_file_combobox->clear();
        song_file_combobox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\226\260\345\242\236\351\240\205\347\233\256", Q_NULLPTR)
        );
        previous_btn->setText(QString());
        play_pause_btn->setText(QApplication::translate("Widget", "pause", Q_NULLPTR));
        next_btn->setText(QString());
        current_time_lab->setText(QApplication::translate("Widget", "00:00:00", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
        total_time_lab->setText(QApplication::translate("Widget", "00:00:00", Q_NULLPTR));
        voice_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
