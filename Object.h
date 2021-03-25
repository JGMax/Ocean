//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_OBJECT_H
#define OCEAN_OBJECT_H
#include "Common.h"
#include "Cell.h"

class Cell;
class Object {
    friend Cell;
 protected:
    Cell* cell;
    objectType type;
    int age = 0;
    int size = 0;
    bool alive = true;
    void increaseAge();
    bool checkAge() const;
    static int getRandom(int max);
 private:
    char getSymbolByAging(char ifTrue, char ifFalse) const;
 public:
    Object(objectType type, Cell* cell) : type(type), cell(cell) { };
    virtual ~Object();

    virtual void live() = 0;
    objectType getType() const;
    void changeCell(Cell* cell);
    Cell* getCell() const;
    void death();
    bool isAlive() const;
    char getSymbol();
    int getSize() const;
};

#endif //OCEAN_OBJECT_H
