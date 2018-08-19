#ifndef DRIVER_H
#define DRIVER_H

class DriverInterface {
  public:
    float pos [2] = {0, 0};
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void turn() = 0;
    DriverInterface() {}

  protected:
    float speed;
    float orientation;
};

#endif
