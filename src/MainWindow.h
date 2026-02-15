//
// Created by define on 13.02.2026.
//

#ifndef AUDIOPLAYER_MAINWINDOW_H
#define AUDIOPLAYER_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "AudioPlayer/AudioPlayer.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAudioPlayerStateChanged(const QMediaPlayer::PlaybackState &state) const;

private:
    AudioPlayer m_audio_player;
    QPushButton                 *m_start_button = nullptr;
    QPushButton                 *m_stop_button  = nullptr;
    QLabel                      *m_label        = nullptr;
};

#endif //AUDIOPLAYER_MAINWINDOW_H