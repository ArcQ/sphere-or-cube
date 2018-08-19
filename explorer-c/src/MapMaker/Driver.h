#ifndef DRIVER_H
#define DRIVER_H

typedef struct {
  float pos[2];
  float speed;
  // degree rotation from original position
  float orientation;
} DriverState; 

typedef struct {
  DriverState *driverState;
  void (* startEngine)();
  void (* stopEngine)();
  void (* turn)(float deg);
} DriverInterface;

#endif
