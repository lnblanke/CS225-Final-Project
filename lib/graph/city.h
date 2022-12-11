#ifndef CITY_H
#define CITY_H

#include "vertex.h"
#include <cmath>

namespace graph {
    /*
    Class for a node
    */
    class City: public graph::Vertex {
    private:
        /*
        The axis of the node in the world
        axis.first: latitude, the vertical value of the point, should in [-90, 90]
        axis.second: longitude, the horizontal value of the point, should be in [-180, 180]
        */
        std::pair<double, double> axis_;
        size_t population_;

    public:
        /*
        Initialize a city with name and coordinate
        name: name of the city
        lat: latitude of the city
        lon: longitude of the city
        */
        City(const std::string& name, double lat, double lon, size_t population): Vertex(name) {
            axis_ = {lat, lon};
            population_ = population;
        }

        City(const City& other): Vertex(other) {
            axis_ = other.axis_;
            population_ = other.population_;
        }

        City& operator=(const City& other) {
            if (*this == other) return *this;

            axis_ = other.axis_;
            population_ = other.population_;

            return *this;
        }

        /*
        Return the latitude of the city
        */        
        inline double getLatitude() const { return axis_.first; }
        
        /*
        Return the longitude of the city
        */
        inline double getLongitude() const { return axis_.second; }

        inline size_t getPopulation() const { return population_; }

        bool operator<(const City& other) {
            return axis_ < other.axis_;
        }

        City& operator+=(const City& other) {
            population_ += other.population_;

            return *this;
        }
    };

    inline double getDistance(const City* c1, const City* c2) {
        double lat1 = 110.574 * c1->getLatitude();
        double lng1 = 111.320 * cos(c1->getLatitude() / 180 * M_PI) * c1->getLongitude();
        double lat2 = 110.574 * c2->getLatitude();
        double lng2 = 111.320 * cos(c2->getLatitude() / 180 * M_PI) * c2->getLongitude();

        return sqrt((lat1 - lat2) * (lat1 - lat2) + (lng1 - lng2) * (lng1 - lng2));
    }
}

#endif