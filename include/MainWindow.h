//
// Created by define on 17.02.2026.
//

#ifndef AUDIOPLAYER_MAINWINDOW_H
#define AUDIOPLAYER_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "AudioPlayer.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void onAudioPlayerStateChanged(const QMediaPlayer::PlaybackState &state) const;

private:
    Ui::MainWindow                         *ui;
    AudioPlayer                  _audio_player;
    QPushButton                 *_start_button = nullptr;
    QPushButton                 *_stop_button  = nullptr;
    QLabel                      *_label        = nullptr;

};


#endif //AUDIOPLAYER_MAINWINDOW_H