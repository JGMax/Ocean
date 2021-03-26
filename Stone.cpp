//
// Created by WorkSpace on 25.03.2021.
//

#include "Stone.h"

void Stone::live() {
    if(isAlive()) {
        increaseAge();
        if (!checkAge()) {
            death();
        }
    }
}

bool Stone::checkAge() {
    return age < deathAge;
}
