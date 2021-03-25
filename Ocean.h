//
// Created by WorkSpace on 25.03.2021.
//

#ifndef OCEAN_OCEAN_H
#define OCEAN_OCEAN_H

#include "Common.h"
#include "Cell.h"
#include "Object.h"

#include <vector>
#include <string>
#include <map>
#include <list>

class Cell;
class Object;

class Ocean {
 private:
    int step = 0;
    Cell **cells;
    std::list<Object*> stuff;
    void makeOcean();
    void setSpecies();
    static int getRandom(int max);
    std::vector<Cell*> getEmptyCells() const;
    static Object* getObject(objectType type, Cell* cell);
    void clearStuff();
    std::map<std::string, int> calcStuff() const;
    static void printStats(std::map<std::string, int> stats) ;

 public:
    Ocean();
    ~Ocean();
    void printOcean() const;
    void run();
    Cell* getCell(Pair crd);
    void addToStuff(Object* object);
};

#endif //OCEAN_OCEAN_H
