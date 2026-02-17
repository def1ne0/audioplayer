//
// Created by define on 17.02.2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <qobject.h>
#include "../../include/MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _audio_player(AudioPlayer {
          QUrl::fromLocalFile(
        "/home/define/Documents/cpp_tasks/audioplayer/assets/Linkin Park - In The End.mp3")
        }) {

    ui->setupUi(this);

    connect(ui->_start_button, &QPushButton::clicked, [this] { _audio_player.start(); });
    connect(ui->_stop_button, &QPushButton::clicked, [this] { _audio_player.stop(); });
    connect(&_audio_player, &AudioPlayer::stateChanged, this, &MainWindow::onAudioPlayerStateChanged);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onAudioPlayerStateChanged(const QMediaPlayer::PlaybackState &state) const {
    switch (state) {
        case QMediaPlayer::PlaybackState::PlayingState:
            ui->_status_label->setText("music started");
            break;
        case QMediaPlayer::PlaybackState::StoppedState:
            ui->_status_label->setText("music stopped");
            break;
        case QMediaPlayer::PlaybackState::PausedState:
            ui->_status_label->setText("music paused");
            break;
    }
}
