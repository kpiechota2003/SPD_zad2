#include <iostream>
#include "ProblemP2.h"

int main() {
    int common_seed = 1;
    ProblemP2 p2;

    std::cout << "LSA: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.LSA();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "LPT: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.LPT();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "PD: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.PD();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "PZ: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.PZ();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;


    return 0;
}
