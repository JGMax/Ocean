//
// Created by WorkSpace on 25.03.2021.
//

#include <vector>
#include "Predator.h"

void Predator::decreaseSatiety() {
    satiety *= SATIETY_DECREASE;
}

bool Predator::isHungry() const {
    return satiety < size;
}

bool Predator::isVeryHungry() const {
    return satiety < double(size) / 10;
}

void Predator::live() {
    decreaseSatiety();
    Prey::live();
    if(satiety < double(size) / 10000) {
        cell->killMe();
    }
}

void Predator::move() {
    Pair crd = cell->getCoordinates();
    std::vector <Cell*> emptyCells;
    std::vector <Cell*> preyCells;
    std::vector <Cell*> predatorCells;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            Cell* cellToMove = cell->getCell({ crd.x + i, crd.y + j });
            if (isPrey(cellToMove)) {
                preyCells.push_back(cellToMove);
            } else if(isEmpty(cellToMove)) {
                emptyCells.push_back(cellToMove);
            } else if(isFriend(cellToMove)) {
                predatorCells.push_back(cellToMove);
            }
        }
    }

    std::vector<Cell*> food;
    if(isVeryHungry()) {
        if (preyCells.empty() && predatorCells.empty()) {
            food = emptyCells;
        } else {
            food = uniteVectors(preyCells, predatorCells);
        }
    } else if (isHungry()) {
        if (preyCells.empty()) {
            food = emptyCells;
        } else {
            food = preyCells;
        }
    } else {
        food = uniteVectors(preyCells, emptyCells);
    }

    if(!food.empty()) {
        eat(getCell(food), !predatorCells.empty());
    }
}

std::vector<Cell *> Predator::uniteVectors(std::vector<Cell*> vector1,
                                           std::vector<Cell*> vector2) {
    std::vector<Cell*> food;
    int size = vector1.size() + vector2.size();
    for (int i = 0; i < size; i++) {
        if (i < vector1.size()) {
            food.push_back(vector1[i]);
        } else {
            food.push_back(vector2[i - vector1.size()]);
        }
    }
    return food;
}

bool Predator::isPrey(Cell *cell) {
    return cell->getType() == PREY;
}

void Predator::eat(Cell* dest, bool hasFriends) {
    if (dest->getType() == PREY || dest->getType() == PREDATOR) {
        if (dest->getType() == PREDATOR) {
            if (getRandom(2)) {
                eat(dest->getObject());
                dest->killMe();
            } else {
                ((Predator*)dest->getObject())->eat(this);
                cell->killMe();
                return;
            }
        } else {
            eat(dest->getObject());
            dest->killMe();
        }
    }

    if (doReproduction(PREDATOR_REPRODUCTION_CYCLE)) {
        int minSize = 1;

        if (hasFriends) {
            minSize = getRandom(MAX_PREDATOR_SIZE / 2);
        }
        Object* object = new Predator(cell, minSize);
        cell->setObject(object);
        cell->addToStuff(object);
    } else {
        cell->clearMe();
    }

    changeCell(dest);
}

void Predator::eat(Object* object) {
    satiety += object->getSize() * FOOD_EFFECTIVENESS;
}
