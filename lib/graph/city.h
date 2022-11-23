#ifndef CITY_H
#define CITY_H

#include "node.h"

namespace graph {
    /*
    Class for a node
    */
    class City: public graph::Node {
    private:
        /*
        The axis of the node in the world
        axis.first: latitude, the vertical value of the point, should in [-90, 90]
        axis.second: longitude, the horizontal value of the point, should be in [-180, 180]
        */
        std::pair<double, double> axis_;

    public:
        /*
        Initialize a city with name and coordinate
        name: name of the city
        lat: latitude of the city
        lon: longitude of the city
        */
        City(const std::string& name, double lat, double lon): Node(name) {
            axis_ = {lat, lon};
        }

        /*
        Return the latitude of the city
        */        
        inline double getLatitude() { return axis_.first; }
        
        /*
        Return the longitude of the city
        */
        inline double getLongitude() { return axis_.second; }
    };
}

#endif