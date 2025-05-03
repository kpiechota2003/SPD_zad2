#include <iostream>
#include "ProblemP2.h"
#include "ProblemP3.h"

void P2_test();

int main() {
    int common_seed = 1;
    ProblemP3 p3;
    std::cout << "PD: " << std::endl;
    p3.generateTasks(5, 5, common_seed);
    p3.PD();
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    return 0;
}

void P2_test() {
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

    std::cout << "PTAS: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.PTAS(5);
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "FPTAS: " << std::endl;
    p2.generateTasks(10, 10, common_seed);
    p2.FPTAS(3);
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;
}