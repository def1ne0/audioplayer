//
// Created by define on 15.02.2026.
//

#include "../../include/AudioPlayer.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <utility>

AudioPlayer::AudioPlayer(QUrl url)
    : _player(new QMediaPlayer),
      _output(new QAudioOutput),
      _url(std::move(url)) {

    _player->setAudioOutput(_output);
    _player->setSource(_url);
}

void AudioPlayer::loadFromAssets(const QUrl &url) {
    _url = url;
}

void AudioPlayer::start() {
    _player->setSource(_url);
    _player->play();

    emit stateChanged(QMediaPlayer::PlaybackState::PlayingState);
}

void AudioPlayer::stop() {
    _player->stop();

    emit stateChanged(QMediaPlayer::PlaybackState::StoppedState);
}

QMediaPlayer::PlaybackState AudioPlayer::getState() const {
    return _player->playbackState();
}