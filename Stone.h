//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_STONE_H
#define OCEAN_STONE_H

#include "Common.h"
#include "Object.h"

class Stone : public Object {
 private:
    int deathAge = DEATH_AGE * (getRandom(DEATH_AGE) + 1);
    bool checkAge();
 public:
    explicit Stone(Cell* cell) : Object(STONE, cell) {}
    void live() override;
};

#endif //OCEAN_STONE_H
