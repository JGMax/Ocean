//
// Created by WorkSpace on 25.03.2021.
//

#include <ctime>
#include <iostream>
#include "Object.h"

Object::~Object() {
    this->cell = nullptr;
}

objectType Object::getType() const {
    return type;
}

void Object::changeCell(Cell *cell) {
    cell->setObject(this);
}

Cell *Object::getCell() const {
    return cell;
}

void Object::increaseAge() {
    age++;
}

char Object::getSymbol() {
    switch (type) {
        case PREY:
            return getSymbolByAging(PREY_LARGE_SYMBOL,
                                    PREY_SMALL_SYMBOL);
        case PREDATOR:
            return getSymbolByAging(PREDATOR_LARGE_SYMBOL,
                                    PREDATOR_SMALL_SYMBOL);
        case STONE:
            return getSymbolByAging(STONE_SMALL_SYMBOL,
                                    STONE_LARGE_SYMBOL);
        default:
            return NOTHING_SYMBOL;
    }
}

char Object::getSymbolByAging(char elder, char younger) const {
    if (age > DEATH_AGE / 2) {
        return elder;
    } else {
        return younger;
    }
}

bool Object::checkAge() const {
    return age < DEATH_AGE;
}

int Object::getRandom(int max) {
    unsigned int seed = time(nullptr);
    return rand_r(&seed) % max;
}

int Object::getSize() const {
    return size;
}

void Object::death() {
    alive = false;
}

bool Object::isAlive() const {
    return alive;
}
