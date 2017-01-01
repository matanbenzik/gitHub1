#ifndef SETTINGUOGOOGLETEST_BaseCab_H
#define SETTINGUOGOOGLETEST_BaseCab_H

#include "Point.h"
#include "GridNode.h"
#include "Passenger.h"
#include "Structure.h"
#include "Manufacturer.h"
#include "Color.h"
#include "Grid.h"


class BaseCab {

protected:
    int cabId;
    int numOfKmPassed;
    int velocity;
    int taxiType;
    double coEfficient;
    Manufacturer manufacturer;
    Color color;
    GridNode* location;
    Structure* map;

public:

    /**
     * constructor.
     */
    BaseCab();

    /**
     * constructor.
     * @param cabId is the cab's id.
     * @param taxiType is a number representing the taxi type - 1 standard , 2- luxury.
     * @param manufacturer is a char representing the manufacturer of the car(will be made into enum).
     * @param color is a char representing the color of the car(will be made into enum).
     */
    BaseCab(int cabId, int taxiType, char manufacturer, char color,Structure* map);

    /**
     * returs the BaseCab's id.
     * @return the BaseCab's id.
     */
    int getCabId();

    /**
     * return the num of km passed.
     * @return the num of km passed.
     */
    int getNumOfKmPassed();

    /**
     * returns the manufacturer(enum).
     * @return the manufacturer(enum).
     */
    Manufacturer getManufacturer();

    /**
     * returns the color(enum).
     * @return the color(enum).
     */
    Color getColor();

    /**
    * get the current location of the taxiBaseCab.
    * @return a pointer to GridNode that is the specific node that the taxi is onn, on the grid.
    */
    GridNode *getLocation();

    /**
     * set the current location of the taxiBaseCab.
     * @param location is a pointer to the node that the taxi BaseCab is at right now.
     */
    void setLocation(GridNode *location);

    /**
     * returns a point representation of the taxi's location.
     * @return a point representing the taxi's location.
     */
    Point returnLocationInPoint();

    /**
     * moves the BaseCab meaning changing its location gridNode to one of its neighbors.
     * this function will be virtual because the deriven class called luxuryBaseCab will be faster
     * and we want its function to be the one to work when the function is called.
     */
    virtual void move( Point point )=0;

};

#endif //SETTINGUOGOOGLETEST_BaseCab_H


