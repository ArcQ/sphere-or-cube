#include "../../../lib/catch/catch.hpp"
#include "Driver.h"
#include "MapMaker.h"

class TestDriver: public DriverInterface {
  public:
    float pos [2] = {0,0};
    void startEngine() {
    };
    void stopEngine() {
    };
    void turn() {
    };
    TestDriver() { }

  protected:
    float speed;
    float orientation;
};

bool arePosEq (float pos1 [2], float pos2 [2]) {
  return (pos1[0] ==  pos2[0] && pos1[1] == pos2[1]);
}

TEST_CASE( "hitting barriers should do something", "[explorer]" ) {
  int barrierOne [2][2];

  TestDriver* testDriver = new TestDriver();
  MapMaker* testMapMaker = new MapMaker(testDriver);
  /*  */
  /* REQUIRE( v.size() == 5 ); */
  /* REQUIRE( v.capacity() >= 5 ); */
  /*  */
  SECTION( "should move forward if not hitting a barrier" ) {
    float initialPos [2] = {0,0};
    float pos [2] = testDriver -> pos;
    REQUIRE(arePosEq(pos, initialPos);
    REQUIRE(2 == 1);
  }
  SECTION( "hitting 4 barriers should stop algorithm" ) {
  }
  SECTION( "hitting a barrier should calculate distance from beginning point" ) {
  }
  /* int theAnswer = 0 */
  // CAPTURE( v );
  // INFO(theAnswer)
}
