//
// Created by truma on 11/23/2020.
//

#ifndef MONTECARLOPI_SIMULATION_H
#define MONTECARLOPI_SIMULATION_H


#include <vector>

class Simulation {
public:
    Simulation();
    std::vector<float> generateCoordinate(int dimension);
    float distanceToOrigin(std::vector<float>);
    int get_p_circle() const;
    int get_p_total() const;
    void add_p_circle();
    void add_p_total();
    float run(int loops, double dimension);
private:
    int p_circle;
    int p_total;
};


#endif //MONTECARLOPI_SIMULATION_H
