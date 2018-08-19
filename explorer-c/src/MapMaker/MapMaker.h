#ifndef MAPMAKER_H 
#define MAPMAKER_H
#include "Driver.h"

class MapMaker {
  public:
    float pos [2] = {0, 0};

    MapMaker(DriverInterface* _driver) {
      driver = _driver;
    }
    DriverInterface* driver;
    int explore();

  protected:
    float clock;
};


#endif
