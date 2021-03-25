//
// Created by WorkSpace on 25.03.2021.
//

#include "Cell.h"
#include "Stone.h"

Object *Cell::getObject() const {
    return object;
}

void Cell::setObject(Object *object) {
    if (object != nullptr) {
        clearMe();
        this->object = object;
        this->type = object->getType();
        object->cell = this;
    }
}

void Cell::killMe() {
    if (type == NOTHING) {
        return;
    }
    object->death();

    if (killedObjects >= PILED_BODY) {
        type = STONE;
        object = new Stone(this);
        killedObjects = 0;
    } else {
        if (type != STONE) {
            killedObjects++;
        }
        type = NOTHING;
        object = nullptr;
    }
}

char Cell::getSymbol() const {
    switch (type) {
        case NOTHING:
            return NOTHING_SYMBOL;
        default:
            return object->getSymbol();
    }
}

Pair Cell::getCoordinates() const {
    return crd;
}

Cell *Cell::getCell(Pair crd) const {
    Cell* cell = ocean->getCell(crd);
    return cell;
}

void Cell::clearMe() {
    type = NOTHING;
    object = nullptr;
}

objectType Cell::getType() const {
    return type;
}

Cell::~Cell() {
    delete object;
    ocean = nullptr;
}

void Cell::init(Pair crd, Ocean *ocean) {
    this->ocean = ocean;
    this->crd = crd;
}

void Cell::addToStuff(Object* object) {
    ocean->addToStuff(object);
}
