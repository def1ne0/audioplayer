//
// Created by define on 13.02.2026.
//

#include <QVBoxLayout>
#include <qobject.h>

#include "MainWindow.h"

void MainWindow::onAudioPlayerStateChanged(const QMediaPlayer::PlaybackState &state) const {
    switch (state) {
        case QMediaPlayer::PlaybackState::PlayingState:
            m_label->setText("music started");
            break;
        case QMediaPlayer::PlaybackState::StoppedState:
            m_label->setText("music stopped");
            break;
        case QMediaPlayer::PlaybackState::PausedState:
            m_label->setText("music paused");
            break;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_audio_player(AudioPlayer {
          QUrl::fromLocalFile(
              "/home/define/Documents/cpp_tasks/audioplayer/assets/Linkin Park - In The End.mp3")
              }) {

    // SAFETY: QT will manage memory correctly
    const auto widget = new QWidget(this);
    const auto layout = new QVBoxLayout(widget);

    m_start_button = new QPushButton("start", widget);
    m_stop_button = new QPushButton("stop", widget);
    m_label = new QLabel("not started", widget);

    connect(m_start_button, &QPushButton::clicked, [this] { m_audio_player.start(); });
    connect(m_stop_button, &QPushButton::clicked, [this] { m_audio_player.stop(); });
    connect(&m_audio_player, &AudioPlayer::stateChanged, this, &MainWindow::onAudioPlayerStateChanged);

    layout->addWidget(m_start_button);
    layout->addWidget(m_stop_button);
    layout->addWidget(m_label);

    layout->setAlignment(Qt::AlignCenter);

    setCentralWidget(widget);
}
