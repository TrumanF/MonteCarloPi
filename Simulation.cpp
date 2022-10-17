//
// Created by truma on 11/23/2020.
//

#include <random>
#include "Simulation.h"
#include <cmath>
#include "GenerateCN.h"
#include <ctime>
#include <iostream>
#include <fstream>
Simulation::Simulation() {
    srand(time(NULL));
    p_circle = 0;
    p_total = 0;
}

std::vector<float> Simulation::generateCoordinate(int dimension) {
    std::vector<float> coordinate;
    for(int i = 0; i < dimension; i++) {
        // generate number from 0 to .5, inclusive
        double r = (static_cast <double> (rand()) / static_cast <double> (RAND_MAX))/2;
        coordinate.emplace_back(r);
    }
    return coordinate;
}

float Simulation::distanceToOrigin(std::vector<float> coordinate) {
    float total;
    // using the distance formula
    for(float& coord : coordinate){
        total += pow(coord, 2);
    }
    return sqrt(total);
}

int Simulation::get_p_circle() const{
    return p_circle;
}
int Simulation::get_p_total() const{
    return p_total;
}

void Simulation::add_p_circle(){
    p_circle += 1;
}
void Simulation::add_p_total(){
    p_total += 1;
}

float Simulation::run(int loops, double dimension) {
    double r = 0.5;
    std::ofstream log;
    log.open("data.txt", std::ios_base::out | std::ios_base::trunc);
    for(int i = 0; i < loops; i++){
        std::vector<float> coordinate = generateCoordinate(dimension);
        float distance = distanceToOrigin(coordinate);
        if(distance <= r){
            add_p_circle();
        }
        add_p_total();
        if(i%100 == 0) {
            log << pow(get_p_circle()/(GenerateCN(dimension + 1).getCn(dimension) * pow(r, dimension) * get_p_total()), (2/dimension)) << std::endl;
        }


    }
    log.close();
    return pow(get_p_circle()/(GenerateCN(dimension + 1).getCn(dimension) * pow(r, dimension) * get_p_total()), (2/dimension));

}
