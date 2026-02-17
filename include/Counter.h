//
// Created by define on 13.02.2026.
//

#ifndef AUDIOPLAYER_COUNTER_H
#define AUDIOPLAYER_COUNTER_H
#include <qobject.h>

class Counter : public QObject{
    Q_OBJECT
public:
    Counter() = default;
    void increase();
    [[nodiscard]] int get() const;

signals:
    void increased(int newValue);
private:
    int value {};
};

#endif //AUDIOPLAYER_COUNTER_H