#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setWindowTitle("奇怪的(´･ω･`)增加了-音樂播放器");
    w.setWindowIcon(QPixmap(":/images/music_player.png"));
    w.setFixedSize(w.width(),w.height());
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);
    w.show();





    return a.exec();
}
