//
// Created by define on 15.02.2026.
//

#ifndef AUDIOPLAYER_AUDIOPLAYER_H
#define AUDIOPLAYER_AUDIOPLAYER_H

#include <qobject.h>
#include <QMediaPlayer>
#include <QAudioOutput>

class AudioPlayer : public QObject {
    Q_OBJECT
public:
    explicit                                  AudioPlayer(QUrl url);
    void                                      loadFromAssets(const QUrl &url);
    void                                      start();
    void                                      stop();
    [[nodiscard]] QMediaPlayer::PlaybackState getState() const;

signals:
    void stateChanged(const QMediaPlayer::PlaybackState &newState);

private:
    QMediaPlayer *_player = nullptr;
    QAudioOutput *_output = nullptr;
    QUrl          _url;
};


#endif //AUDIOPLAYER_AUDIOPLAYER_H