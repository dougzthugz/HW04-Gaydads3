#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
//#include "HW04 GaydadsApp.h"
#include "Starbucks.h"
#include "gaydadsStarbucks.h"
#include <fstream>
#include <cstdlib>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_GaydadsApp : public AppBasic {
    public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry* readFile();
};

Entry* HW04_GaydadsApp::readFile(){
	string line;
	double x, y;
	ifstream myFile("Starbucks_2006.csv");
	int numItems = 7655;
	

	Entry* arr = new Entry[numItems];
	for(int i = 0; i < numItems; i++){
		getline(myFile, line, ',');
		arr[i].identifier = line;
		getline(myFile, line, ',');
		x = atof(line.c_str());
		arr[i].x = x;
		getline(myFile, line, '\r');
		y = atof(line.c_str());
		arr[i].y = y;
	}
	return arr;
}

void HW04_GaydadsApp::setup()
{
	
	Entry* arr = readFile();

	HW04_GaydadsApp::console() << arr[1].identifier<< "things" <<std::endl;
}

void HW04_GaydadsApp::mouseDown( MouseEvent event )
{
}

void HW04_GaydadsApp::update()
{
}

void HW04_GaydadsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_GaydadsApp, RendererGl )
