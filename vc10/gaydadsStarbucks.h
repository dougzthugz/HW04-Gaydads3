#include "Starbucks.h"
using namespace std;

class gaydadsStarbucks : public Starbucks{
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
};