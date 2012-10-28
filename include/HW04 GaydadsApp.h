#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "gaydadsStarbucks.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_gaydads : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry* readFile();
};