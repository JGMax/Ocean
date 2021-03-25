//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_COMMON_H
#define OCEAN_COMMON_H

#define PILED_BODY 50

#define PREY_SMALL_SYMBOL 'o'
#define PREY_LARGE_SYMBOL 'O'
#define PREDATOR_SMALL_SYMBOL 'p'
#define PREDATOR_LARGE_SYMBOL 'P'
#define STONE_SMALL_SYMBOL 'x'
#define STONE_LARGE_SYMBOL 'X'
#define NOTHING_SYMBOL '.'

const int OCEAN_X_SIZE = 120;
const int OCEAN_Y_SIZE = 17;

#define PREDATOR_DEFAULT_POPULATION 10
#define PREY_DEFAULT_POPULATION 20
#define STONE_DEFAULT_POPULATION 10

#define DEATH_AGE 50

#define MAX_PREY_SIZE 50
#define PREY_REPRODUCTION_CYCLE 2

#define MAX_PREDATOR_SIZE 100
#define PREDATOR_REPRODUCTION_CYCLE 4
#define SATIETY_DECREASE 0.8
#define FOOD_EFFECTIVENESS 0.5


enum objectType { PREY, PREDATOR, STONE, NOTHING };

struct Pair {
    int x;
    int y;
};

#endif //OCEAN_COMMON_H