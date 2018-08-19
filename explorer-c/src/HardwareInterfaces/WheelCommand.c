#ifndef WHEELCOMMAND_H
#define WHEELCOMMAND_H

typedef struct {
  void (* startEngine)();
  void (* stopEngine)();
  void (* turn)(float deg);
} WHEELCOMMAND_INTERFACE;

#endif
