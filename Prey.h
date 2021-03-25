//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_PREY_H
#define OCEAN_PREY_H

#include "Common.h"
#include "Object.h"
#include "Cell.h"


class Prey : public Object {
 protected:
    int reproductionCycle = 0;
    bool isFriend(Cell* cell) const;
    static bool isEmpty(Cell* cell);
    virtual void move();
    bool doReproduction(int cycle = PREY_REPRODUCTION_CYCLE);
    void makeStep(Cell* dest, bool doReproduction, bool hasFriends);
    static Cell* getCell(std::vector<Cell*>& availableCells);
 public:
    explicit Prey(Cell* cell, int minSize = 1);
    void live() override;
};

#endif //OCEAN_PREY_H
