#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static struct DriverState driverState = {
  {0, 0}, 0, 0
};

/** 
 * setTimeout Implementation simple timeout
 * @brief 
 *
 * @usage: setTimeout(1000) - timeout on 1 second
 * @param milliseconds
 */

void setTimeout(int milliseconds)
{
    // If milliseconds is less or equal to 0
    // will be simple return from function without throw error
    if (milliseconds <= 0) {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // a current time of milliseconds
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // needed count milliseconds of return from this timeout
    int end = milliseconds_since + milliseconds;

    // wait while until needed time comes
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}

void startEngine() {
  
}

void stopEngine() {
}

void turn() {
}

struct DriverState getDriverState() {
  return driverState;
}
