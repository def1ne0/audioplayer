//
// Created by define on 15.02.2026.
//

#include "AudioPlayer.h"
#include <QMediaPlayer>
#include <QAudioOutput>

AudioPlayer::AudioPlayer(const QUrl &url)
    : m_player(new QMediaPlayer),
      m_output(new QAudioOutput),
      m_url(url) {

    m_player->setAudioOutput(m_output);
    m_player->setSource(m_url);
}

void AudioPlayer::loadFromAssets(const QUrl &url) {
    m_url = url;
}

void AudioPlayer::start() {
    m_player->setSource(m_url);
    m_player->play();

    emit stateChanged(QMediaPlayer::PlaybackState::PlayingState);
}

void AudioPlayer::stop() {
    m_player->stop();

    emit stateChanged(QMediaPlayer::PlaybackState::StoppedState);
}

QMediaPlayer::PlaybackState AudioPlayer::getState() const {
    return m_player->playbackState();
}