//
// Created by define on 13.02.2026.
//

#include <print>
#include "Counter.h"

void Counter::increase() {
    emit increased(++value);
}

int Counter::get() const {
    return value;
}