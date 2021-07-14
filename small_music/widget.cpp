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

void Widget::init() //初始化
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

    ui->voice_slider->setValue(30);
    player->setVolume(30);
    read_music_play();
}

void Widget::button_icon(QToolButton *to,QString text, QString image) //更換play_pause圖示
{
    to->setText(text);
    to->setIcon(QPixmap(image));
    to->setIconSize(QSize(100,100));
}

void Widget::clk_play_pause() //播放、暫停
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

void Widget::clk_next_btn() //下一首
{
    ++play_song_number;

    if(player->duration())
    {
        if(play_song_number == (songInfo[play_dir].count()-1))
            play_song_number=2;

        play_song();
    }
}

void Widget::default_play_next() //自動播放
{
    ++play_song_number;

    if(play_song_number == (songInfo[play_dir].count()-1)) //空格
        play_song_number=2;

    play_song();
}

void Widget::clk_previous_btn() //上一首
{
    if(play_song_number>2 && player->duration())
    {
        --play_song_number;
        play_song();
    }
}

void Widget::mute_vocalize_btn() //靜音按鈕
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

QStringList Widget::read_mp3_txt(QDir dir,QString type) //讀取目錄的附檔名選擇
{
    return dir.entryList(QStringList()<<type,QDir::Files | QDir::Readable, QDir::Name);
}

void Widget::open_dir_dialog()//讀取音樂 按鈕
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

void Widget::save_file(QString URL,QString dirName,QStringList songList) //存取讀取的音樂存到系統中
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

void Widget::read_music_play() //讀取現在、之前新增的目錄
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
        if(songInfo[i][1] == moment_song_name2)
            play_dir=i;

    if(default_read)
        read_saveSong();

    if(play_dir >= songInfo.count())
        play_dir=0;

    if(play_song_number>=songInfo[play_dir].count())
        play_song_number=2;

    add_combobox();
    get_lyrics();
    play_song();
}

void Widget::clk_combobox(int item) //切換目錄
{

    if(delete_file)
    {
        delete__combobox_itme(item);




    }else
    {
        for(int i=0; i<songInfo.count();i++)
        {
            if(songInfo[i][1] == ui->song_file_combobox->itemText(item))
            {

                play_dir=i;
                play_song_number=2;
                get_lyrics();
                play_song();
                break;
            }
        }
    }
}

void Widget::add_combobox() //增加目錄到下拉式選單
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

void Widget::delete__combobox_itme(int item) //刪除目錄
{
        disconnect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));

        ui->song_file_combobox->removeItem(item);

        QFile::remove(QDir::currentPath()+"/"+saveDir+"/"+songInfo[item][1]+".txt");

        ui->delete_file_btn->setChecked(false);
        delete_file=false;

        for(int i=0; i<ui->song_file_combobox->count();i++)
        {
            if(songInfo[play_dir][1] == ui->song_file_combobox->itemText(i))
                ui->song_file_combobox->setCurrentIndex(i);
        }


        connect(ui->song_file_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(clk_combobox(int)));
}

void Widget::clk_delete_btn() //刪除目錄鍵
{
    delete_file=false;

    if(ui->delete_file_btn->isChecked())
        delete_file=true;
}

void Widget::set_song_name() //顯示音樂名稱
{
   ui->song_name_lab->setText(songInfo[play_dir][play_song_number]);
}

void Widget::move_slider(int sound) //調音量
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

void Widget::play_song() //播放音樂時的前置處理
{



    lyrics_isexist();

    if(have_lyric)
        ui->lyrics_lab->setText("");
    else
        ui->lyrics_lab->setText("沒有歌詞");

    set_song_name();

    button_icon(ui->play_pause_btn, "pause",":/images/pause.png");

    moment_song_name=songInfo[play_dir][play_song_number];

    player->setMedia(QUrl::fromLocalFile(songInfo[play_dir][0]+"/"+songInfo[play_dir][play_song_number]));
}

void Widget::play_status(QMediaPlayer::MediaStatus status) //播放暫停鍵
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

QTime Widget::time_change(int times) //音樂毫秒轉換成秒(音樂讀取近來是毫秒)
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

void Widget::getTime(qint64 times) //音樂的總時間
{
    QTime time = time_change(times);

    ui->total_time_lab->setText(time.toString("hh:mm:ss"));
}

void Widget::currentTime(qint64 times) //音樂播放顯示時間
{
    QTime time = time_change(times);
    ui->current_time_lab->setText(time.toString("hh:mm:ss"));

    if(have_lyric)
        show_lyrics(times);
}

void Widget::show_lyrics(qint64 times) //顯示歌詞
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

void Widget::get_lyrics() //取得歌詞名稱(音樂跟歌詞一樣名稱)
{

    QDir dir(songInfo[play_dir][0]);
    song_lyrics = read_mp3_txt(dir,"*txt");
}

void Widget::lyrics_isexist() //判斷播放音樂是否有歌詞
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

void Widget::read_saveSong() //讀取上次播放的音樂位置
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

void Widget::closeEvent(QCloseEvent *event) //關閉儲存播放歌曲
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

Widget::~Widget()
{
    delete ui;
}
