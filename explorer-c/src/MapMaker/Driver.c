#include "Driver.h"

DriverState getInitialDriverState() {
  DriverState driverState = {
    {0,0}, 0, 0
  };
  return driverState;
};

static struct DriverState driverState = {
  {0, 0}, 0, 0
};

struct DriverState {
  int pos[2];
  float speed;
  // degree rotation from original position
  float orientation;
}; 

void startEngine() {

}

startEngine() {
  
}

DriverInterface Driver = {
  getInitialDriverState(),


}
