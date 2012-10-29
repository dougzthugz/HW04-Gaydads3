#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "gaydadsStarbucks.h"
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

node::node(){
	left = NULL;
	right = NULL;
	data = NULL;
}

node::node(Entry* entry){
	left = NULL;
	right = NULL;
	data = entry;
}

gaydadsStarbucks::gaydadsStarbucks(){
	//root->data->identifier = "Root";
}


void gaydadsStarbucks::randomize(Entry* locations, int n){
	int x = 0;
	int tempn = n;
	//Entry* temp_arr = new Entry[n];

	for(int i=0; i<n; i++){
		int random = rand()%tempn + 1;
		Entry temp = locations[random];
		locations[random] = locations[tempn];
		locations[tempn] = temp;
		tempn = tempn - 1;
	}
}

/*node* gaydadsStarbucks::insert(Entry* entry, node* r, bool is_x_level){
	//If at the end of the tree add new entry node
	if(r == NULL) {
        return new node(entry);
	}

	//If entry is a duplicate location don't add new entry
	if((abs((r->data->x) - (entry->x))<=0.00001) && (abs((r->data->y) - (entry->y))<=0.00001)) {
        return r;
	}

	//Determine which side to follow
	//X level
	if(is_x_level == true) {
		if((entry->x) < (r->data->x)) {
			r->left = insert(entry,r->left,!is_x_level);
		}
		else {
			r->right = insert(entry,r->right,!is_x_level);
		}
	}
	//Y level
	else {
		if(entry->y < r->data->y) {
			r->left = insert(entry,r->left,!is_x_level);
		}
		else {
			r->right = insert(entry,r->right,!is_x_level);
		}
	}
	return r;
}

void gaydadsStarbucks::build(Entry* entry, int n){
	//randomize(entry,n);

	tree = new node(entry);
	double distance;
	Entry* temp = &entry[0];
	distance = abs(sqrt(   ((.5-entry[0].x)*(.5-entry[0].x)) + ((.5-entry[0].y)*(.5-entry[0].y))));
	for(int i=0; i<n; i++ ){
		double distance2 = abs(sqrt(   ((.5-entry[0].x)*(.5-entry[0].x)) + ((.5-entry[0].y)*(.5-entry[0].y))));;
		if (distance > distance2) {
			distance = distance2;
			temp = &entry[i];
		}
	}
	//*tree->data=*temp;
	



	/////




	///////




	//insert(temp, tree, false);

	for(int i=1;i<n;i++) {
		insert(&entry[i], tree, true); 
	}
	root = tree;
}*/

void gaydadsStarbucks::build(Entry* c, int n){
	

	
	
	//Array
	Locations = new Entry[n];
for (int i=0; i<n; i++){
	Locations[i] = c[i];
}



}


/*Entry* search(double x, double y, node* r, bool is_x_level) {
	if (r == NULL) {
		return NULL;
	}
	Entry* best_left = NULL;
	Entry* best_right = NULL;

	if(is_x_level) {
		if(r->data->x > x) {
			best_left = search(x,y,r->left,!is_x_level);
		}
		if(best_left == NULL) {
			best_right = search(x,y,r->right,!is_x_level);
		}
	}

	else {
		if(r->data->y > y)
			best_left = search(x,y,r->left,!is_x_level);
		if(best_right == NULL)
			best_right = search(x,y,r->right,!is_x_level);
	}

	if(best_left == NULL && best_right == NULL) {
		return r->data;
	}
	return r->data;
	}
	*/
Entry* gaydadsStarbucks::getNearest(double x, double y){
	/*Entry* nearest = search(x,y,this->tree,true);

	return nearest;
	*/
	
	//Array
	
	double distance = abs(sqrt(   ((x-Locations[0].x)*(x-Locations[0].x)) + ((y-Locations[0].y)*(y-Locations[0].y))));;
	Entry* temp = &(Locations[0]);

	for(int i=1; i<7655; i++ ){
		double distance2 = abs(sqrt(   ((x-Locations[i].x)*(x-Locations[i].x)) + ((y-Locations[i].y)*(y-Locations[i].y))));
		if (distance > distance2) {
			distance = distance2;
			temp = &(Locations[i]);
		}
	}

	Entry* nearest = temp;
	return nearest;





}