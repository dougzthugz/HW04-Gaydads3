#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "HW04_GaydadsApp.h"
#include "Starbucks.h"
#include "GaydadsStarbucks.h"
#include "cinder/Rand.h"
#include <fstream>
#include <cstdlib>

using namespace ci;
using namespace ci::app;
using namespace std;

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
	structure = new gaydadsStarbucks();
	
	Entry* AllStarbucks = readFile();
	Entry* location;
	
	structure->build(AllStarbucks,7655);

	console() << "Hi" << endl;
	
	
	//location = structure->getNearest(.787692839,.62042);
	
	
	location = structure->getNearest(.5,.5);
	HW04_GaydadsApp::console() <<location->identifier <<std::endl;


	//structure->root[1].data;
		int jklm = rand()%100+1;
		int ok = rand()%100+1;
		//HW04_GaydadsApp::console() <<jklm <<std::endl;
		/*HW04_GaydadsApp::console() <<ok <<std::endl;
		HW04_GaydadsApp::console() << structure->root->data->identifier<<std::endl;
	HW04_GaydadsApp::console() << structure->root->right->data->identifier <<structure->root->right->data->x<<std::endl;

	HW04_GaydadsApp::console() << structure->root->left->data->identifier <<structure->root->left->data->x<<std::endl;
	
	HW04_GaydadsApp::console() << structure->root->right->right->data->identifier <<structure->root->right->right->data->y<<std::endl;
	HW04_GaydadsApp::console() << structure->root->right->left->data->identifier <<structure->root->right->left->data->y<<std::endl;

	*/

	//Array Testing
	/*double distance;
	Entry* arr = readFile();
	Entry temp = arr[0];

	distance = abs(sqrt(   ((.787692839-arr[0].x)*(.78769283-arr[0].x)) + ((.62042-arr[0].y)*(.62042-arr[0].y))));

	for(int i=0; i<7655; i++ ){
		double distance2 = abs(sqrt(   ((.787692839-arr[0].x)*(.78769283-arr[0].x)) + ((.62042-arr[0].y)*(.62042-arr[0].y))));;
		if (distance > distance2) {
			distance = distance2;
			temp = arr[i];
		}
	}
	HW04_GaydadsApp::console() << arr[1].identifier<< "things" <<std::endl;
	HW04_GaydadsApp::console() << "change" <<std::endl;
	HW04_GaydadsApp::console() << temp.identifier<<std::endl;*/


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
