// Copyright JMax 2021

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

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

#endif  // INCLUDE_PREY_H_
