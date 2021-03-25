//
// Created by WorkSpace on 25.03.2021.
//

#include "Stone.h"

void Stone::live() {
    increaseAge();
    if (!checkAge()) {
        cell->killMe();
    }
}

bool Stone::checkAge() {
    return age < deathAge;
}
