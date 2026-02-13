//
// Created by define on 13.02.2026.
//

#include <print>

#include <QHBoxLayout>
#include <qobject.h>

#include "MainWindow.h"
#include "Counter.h"

void MainWindow::onCounterChanged(const int &newValue) const {
    if (m_label) {
        m_label->setText(QString::number(newValue));
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_counter(std::make_unique<Counter>()) {

    // SAFETY: QT will manage memory correctly
    const auto widget = new QWidget(this);
    const auto layout = new QHBoxLayout(widget);

    m_button = new QPushButton("click me", widget);
    m_label = new QLabel("0", widget);

    connect(m_button, &QPushButton::clicked, [this] { m_counter->increase(); });
    connect(m_counter.get(), &Counter::increased, this, &MainWindow::onCounterChanged);

    layout->addWidget(m_button);
    layout->addWidget(m_label);
    setCentralWidget(widget);
}
