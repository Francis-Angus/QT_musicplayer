#include "widget.h"
#include "ui_widget.h"
#include "combobox.h"
#include "QFileDialog"
#include "QDebug"
#include "QIODevice"
#include "QTextCodec"
#include "QTime"
#include <QtMultimedia/QMediaPlayer>
#include "windows.h"
#include <QCloseEvent>
#include <QListWidget>
#include <QListWidgetItem>
#include <QComboBox>

Widget::Widget(QWidget *parent):QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
}

void Widget::init() //ok
{

    connect(ui->play_pause_btn,SIGNAL(clicked()),this,SLOT(clk_play_pause()));
    connect(ui->add_file_btn,SIGNAL(clicked()),this,SLOT(open_dir_dialog()));
    connect(ui->next_btn,SIGNAL(clicked()),this,SLOT(clk_next_btn()));
    connect(ui->previous_btn,SIGNAL(clicked()),this,SLOT(clk_previous_btn()));
    connect(ui->delete_file_btn,SIGNAL(clicked()),this,SLOT(clk_delete_btn()));
    connect(ui->voice_btn,SIGNAL(clicked()),this,SLOT(mute_vocalize_btn()));
    connect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));
    connect(ui->voice_slider,SIGNAL(valueChanged(int)),this,SLOT(move_slider(int)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(getTime(qint64))); //取得歌曲時間
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(currentTime(qint64))); //播放歌曲秒數
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(play_status(QMediaPlayer::MediaStatus))); //緩存

    saveDir="info";
    saveSong="save.as";
    moment_song_name2="";
    default_read=true;
    have_lyric=false;
    delete_list=false;
    delete_file=false;

    ui->song_file_combobox->installEventFilter(this);
    ui->voice_slider->setValue(30);
    player->setVolume(30);
    hide_all();
    read_music_play();
}

void Widget::button_icon(QToolButton *to,QString text, QString image) //更換play_pause圖示 ok
{
    to->setText(text);
    to->setIcon(QPixmap(image));
    to->setIconSize(QSize(100,100));
}

void Widget::clk_play_pause() // 撥放 暫停 ok
{

    if(ui->play_pause_btn->text()=="pause" && player->duration())
    {
        button_icon(ui->play_pause_btn, "play",":/images/play.png");
        player->pause();
    }
    else if(player->duration())
    {
        button_icon(ui->play_pause_btn, "pause",":/images/pause.png");
        player->play();
    }
}

void Widget::clk_next_btn() //下一首 ok
{
    ++play_song_number;

    if(player->duration()) //空格
    {
        if(play_song_number == (songInfo[play_dir].count()-1))
            play_song_number=2;

        play_song();
    }

}

void Widget::default_play_next() //ok
{
    ++play_song_number;

    if(play_song_number == (songInfo[play_dir].count()-1)) //空格
        play_song_number=2;

    play_song();
}

void Widget::clk_previous_btn() //上一首 ok
{
    if(play_song_number>2 && player->duration())
    {
        --play_song_number;
        play_song();
    }
}

void Widget::mute_vocalize_btn() //ok
{
    if(ui->voice_slider->value()>0)
    {
        voice_steak=ui->voice_slider->value();
        ui->voice_btn->setIcon(QPixmap(":/images/no_sound"));
        ui->voice_slider->setValue(0);
    }
    else
    {
        ui->voice_slider->setValue(voice_steak);
    }
}

QStringList Widget::read_mp3_txt(QDir dir,QString type) //ok
{
    return dir.entryList(QStringList()<<type,QDir::Files | QDir::Readable, QDir::Name);
}

void Widget::open_dir_dialog()//讀取音樂 ok
{
    QFileDialog * dialog = new QFileDialog();

    dialog->setDirectory("D:/"); //開啟位置

    dialog->setFileMode(QFileDialog::Directory); //讀取資料夾

    if(dialog->exec()) //開啟選擇框
    {

        QDir dir(dialog->selectedFiles().first());

        QStringList music = read_mp3_txt(dir,"*mp3");

        if(music.count()<3)
            return;

        QString moment_song_name= dir.dirName();



        save_file(dir.path(),dir.dirName(),music);

        moment_song_name2 = dir.dirName();

        read_music_play();
    }
}

void Widget::save_file(QString URL,QString dirName,QStringList songList) //存取讀取的音樂存到系統中 ok
{
    if(!QDir(QDir::currentPath()+"/"+saveDir).exists()) //儲存資料夾
        QDir(QDir::currentPath()).mkdir(saveDir);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QFile file(QDir::currentPath()+"/"+saveDir+"/"+dirName+".txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out<<URL<<"\n";
        out<<dirName<<"\n";
        foreach(QString song, songList)
            out<<song<<"\n";

        out.flush();
    }
    file.destroyed();
}

void Widget::read_music_play() //讀取預設內容 ok
{
    play_song_number=2;
    play_dir=0;

    songInfo.clear();

    QDir dir(QDir::currentPath()+"/"+saveDir);

    QStringList music = read_mp3_txt(dir,"*txt");

    if(music.count()<=0)
        return;

    foreach(QString str, music)
    {
        QFile file(dir.path()+"/"+str);

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QStringList song=QString(file.readAll()).split("\n");
            songInfo.append(song);
        }
        file.destroyed();
     }

    for(int i=0;i<songInfo.count();i++)
    {
        if(songInfo[i][1] == moment_song_name2)
            play_dir=i;
    }

    if(default_read)
        read_saveSong();

    if(play_dir >= songInfo.count())
    {
        play_dir=0;

    }


    if(play_song_number>=songInfo[play_dir].count())
        play_song_number=2;




    add_combobox();

    get_lyrics();

    play_song();
}

void Widget::get_lyrics() //ok
{

    QDir dir(songInfo[play_dir][0]);
    song_lyrics = read_mp3_txt(dir,"*txt");
}

void Widget::clk_combobox(int item) //未完成
{
    check_combobox=true;

    if(delete_file)
    {
        delete__combobox_itme(item);
        ui->delete_file_btn->setChecked(false);
        delete_file=false;
    }
    else
    {
        for(int i=0; i<songInfo.count();i++)
        {
            if(songInfo[i][1] == ui->song_file_combobox->itemText(item))
            {
                play_dir=i;
                play_song_number=2;
                break;
            }

        }
        play_song();
    }
}

void Widget::delete__combobox_itme(int item) //未完成
{
        disconnect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));

        ui->song_file_combobox->removeItem(item);

        QFile::remove(QDir::currentPath()+"/"+saveDir+"/"+songInfo[item][1]+".txt");

        connect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));



}

void Widget::add_combobox() //ok
{

    disconnect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));

    ui->song_file_combobox->clear();

    foreach(QStringList song,songInfo)
    {

       ui->song_file_combobox->addItem(song[1]);
    }
     ui->song_file_combobox->setCurrentIndex(play_dir);
     connect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));

}

void Widget::set_song_name() //ok
{
   ui->song_name_lab->setText(songInfo[play_dir][play_song_number]);
   ui->song_name_lab_2->setText(songInfo[play_dir][play_song_number]);
}

void Widget::move_slider(int sound) //ok
{
    player->setVolume(sound);
    ui->voice_slider->setValue(sound);

    if(sound==0)
        ui->voice_btn->setIcon(QPixmap(":/images/no_sound.png"));
    else if(sound <60)
        ui->voice_btn->setIcon(QPixmap(":/images/small_sound.png"));
    else
        ui->voice_btn->setIcon(QPixmap(":/images/large_sound.png"));
}

void Widget::play_song() //ok
{

    ui->lyrics_lab->setText("沒有歌詞");

    lyrics_isexist();

    set_song_name();

    button_icon(ui->play_pause_btn, "pause",":/images/pause.png");

    moment_song_name=songInfo[play_dir][play_song_number];

    player->setMedia(QUrl::fromLocalFile(songInfo[play_dir][0]+"/"+songInfo[play_dir][play_song_number]));
}

void Widget::play_status(QMediaPlayer::MediaStatus status) //ok
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        player->stop();
        default_play_next();
    }

    if (status == QMediaPlayer::InvalidMedia)
        default_play_next();

    if(status == QMediaPlayer::LoadedMedia)
        player->play();
}

QTime Widget::time_change(int times) //ok
{
    qint64 h,m,s;

    times /=1000;

    h = (times)/3600;
    m = (times-(h*3600))/60;
    s = times-(h*3600)-(m*60);

    QTime time;

    time.setHMS(h,m,s);

return time;
}

void Widget::getTime(qint64 times) //ok
{
    QTime time = time_change(times);

    ui->total_time_lab->setText(time.toString("hh:mm:ss"));
}

void Widget::currentTime(qint64 times) //ok
{
    QTime time = time_change(times);
    ui->current_time_lab->setText(time.toString("hh:mm:ss"));

    if(have_lyric)
        show_lyrics(times);
}

void Widget::show_lyrics(qint64 times) //ok
{
    if(iter!=lyric.end())
    {
        if(iter.key() <= (times/1000))
        {
        ui->lyrics_lab->setText(iter.value());
        iter++;
        }
    }
}

void Widget::clk_delete_btn() //ok
{
    delete_file=false;

    if(ui->delete_file_btn->isChecked())
        delete_file=true;
}

void Widget::read_saveSong() //ok
{
    default_read=false;

     QDir dir(QDir::currentPath()+"/"+saveDir);

     QFile file(dir.path()+"/"+saveSong);

     if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QStringList song=QString(file.readAll()).split("\n");
        if(song.count()>=2)
        {
            play_dir=song[0].toInt();
            play_song_number=song[1].toInt();
        }
    }
    file.destroyed();
}

void Widget::lyrics_isexist() //ok
{

    lyric.clear();
    QStringList song_list;
    int sec;

    foreach(QString song, song_lyrics)
    {
        if(song.split(".")[0]==songInfo[play_dir][play_song_number].split(".")[0])
        {
            QDir dir(songInfo[play_dir][0]);
            QFile file(dir.path()+"/"+song);
            if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                song_list=QString(file.readAll()).split("\n");
            }
            file.destroyed();

            for(int i=0;i<song_list.count();i++)
            {
                if(song_list[i].mid(10) != "")
                {
                  sec = (song_list[i].mid(1,2).toInt()*60)+song_list[i].mid(4,2).toInt();
                  lyric.insert(sec,song_list[i].mid(10));
                }
            }
            song_list.clear();
            iter=lyric.begin();
            have_lyric=true;
            return;
        }
    }
    have_lyric=false;
}

void Widget::closeEvent(QCloseEvent *event) //ok
{
    Q_UNUSED(event);

    QFile file(QDir::currentPath()+"/"+saveDir+"/"+saveSong);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out<<play_dir<<"\n";
        out<<play_song_number;
    }
}

void Widget::enterEvent(QEvent* event)
{

    Q_UNUSED(event);

    show_all();


}

void Widget::leaveEvent(QEvent* event)
{


    Q_UNUSED(event);
    if(check_combobox)
        hide_all();
}

void Widget::hide_all()
{
    ui->add_file_btn->hide();
    ui->delete_file_btn->hide();
    ui->previous_btn->hide();
    ui->play_pause_btn->hide();
    ui->next_btn->hide();
    ui->current_time_lab->hide();
    ui->total_time_lab->hide();
    ui->voice_btn->hide();
    ui->voice_slider->hide();
    ui->label_2->hide();
    ui->song_name_lab->hide();
    ui->song_name_lab_2->show();
}

void Widget::show_all()
{
    ui->add_file_btn->show();
    ui->delete_file_btn->show();
    ui->previous_btn->show();
    ui->play_pause_btn->show();
    ui->next_btn->show();
    ui->current_time_lab->show();
    ui->total_time_lab->show();
    ui->voice_btn->show();
    ui->voice_slider->show();
    ui->label_2->show();
    ui->song_name_lab->show();
    ui->song_name_lab_2->hide();
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->song_file_combobox && e->type() ==  QMouseEvent::MouseButtonPress)
    {
        ui->song_file_combobox->showPopup();
        check_combobox=false;

        return true;
    }
    return false;
}




Widget::~Widget()
{
    delete ui;
}
