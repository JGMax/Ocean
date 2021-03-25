//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_PREDATOR_H
#define OCEAN_PREDATOR_H

#include "Prey.h"
#include "Common.h"
#include "Cell.h"

class Predator : public Prey {
 private:
    double satiety = size;
    void move() override;
    void eat(Cell* dest, bool hasFriends);
    static bool isPrey(Cell* cell) ;
    bool isHungry() const;
    bool isVeryHungry() const;
    static std::vector<Cell*> uniteVectors(std::vector<Cell*> vector1,
                                           std::vector<Cell*> vector2);
    void decreaseSatiety();
    void eat(Object* object);
 public:
    explicit Predator(Cell* cell, int minSize = 1) : Prey(cell) {
        type = PREDATOR;
        size = getRandom(MAX_PREDATOR_SIZE - 1) + minSize;
    }
    void live() override;
};

#endif //OCEAN_PREDATOR_H
