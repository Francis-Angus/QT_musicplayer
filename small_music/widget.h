#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QMap>
#include <QtMultimedia/QMediaPlayer>
#include <QCloseEvent>
#include <QComboBox>
#include <QMouseEvent>
#include <QDir>
#include <QEvent>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private:
    Ui::Widget *ui;
    QMediaPlayer * player = new QMediaPlayer;

protected:
    void closeEvent(QCloseEvent* event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);



private slots:
    void clk_play_pause();
    void open_dir_dialog();
    void clk_previous_btn();
    void clk_next_btn();
    void clk_combobox(int);
    void move_slider(int);
    void getTime(qint64);
    void currentTime(qint64);
    void play_status(QMediaPlayer::MediaStatus);
    void delete__combobox_itme(int);
    void clk_delete_btn();
    void mute_vocalize_btn();

public:


   QString saveDir;
   QString saveSong;
   QString moment_song_name;
   QString moment_song_name2;

   int play_song_number;
   int voice_steak;
   bool default_read;
   bool have_lyric;
   int play_dir;
   bool delete_list;
   bool delete_file;
   bool check_combobox;



   QList<QStringList> songInfo;
   QList<QStringList> saveInfo;
   QStringList song_lyrics;

   QMap<int,QString> lyric;
   QMap<int,QString>::iterator iter;

   void button_icon(QToolButton *to,QString text, QString image);
   void init();
   void save_file(QString,QString,QStringList);
   void default_read_folder();
   void read_music();
   void read_music_play();
   void set_song_name();
   void add_combobox();
   void play_song();
   void read_saveSong();
   QTime time_change(int times);
   void lyrics_isexist();
   void get_lyrics();
   void process_lyrics();
   void show_lyrics(qint64);
   void default_play_next();
   void check_clk();
   void hide_all();
   void show_all();
   bool eventFilter(QObject *watched, QEvent *event);


   QStringList read_mp3_txt(QDir,QString);




};

#endif // WIDGET_H
