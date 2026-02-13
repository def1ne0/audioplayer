//
// Created by define on 13.02.2026.
//

#ifndef AUDIOPLAYER_MAINWINDOW_H
#define AUDIOPLAYER_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "Counter.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onCounterChanged(const int&) const;

private:
    std::unique_ptr<Counter> m_counter;
    QPushButton *m_button = nullptr;
    QLabel *m_label = nullptr;
};


#endif //AUDIOPLAYER_MAINWINDOW_H