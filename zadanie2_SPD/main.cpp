#include <iostream>
#include "ProblemP2.h"
#include "ProblemP3.h"

void P2_test1();
void P2_test2();
void P3_test();
void P3_tab();

int main() {
    // P2_test1();
    P3_tab();
    return 0;

}

void P3_test() {
    int common_seed = 1;
    int tasks = 10;
    int max_val =5;
    ProblemP3 p3;
    std::cout << "PD: " << std::endl;
    p3.generateTasks(tasks, max_val, common_seed);
    p3.PD();
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PZ: " << std::endl;
    p3.generateTasks(tasks, max_val, common_seed);
    p3.PZ();
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PTAS: " << std::endl;
    p3.generateTasks(tasks, max_val, common_seed);
    p3.PTAS(tasks/2);
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;
}
void P3_tab() {
    int common_seed = 1;
    int tasks = 10;
    int max_p = 10;
    int min_p = 1;

    ProblemP3 p3;
    std::cout << "PD: " << std::endl;
    p3.generateTasks(tasks, max_p, min_p,common_seed);
    p3.PD();
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PZ: " << std::endl;
    p3.generateTasks(tasks, max_p, min_p, common_seed);
    p3.PZ();
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PTAS n/2: " << std::endl;
    p3.generateTasks(tasks, max_p,min_p, common_seed);
    p3.PTAS(tasks/2);
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PTAS 2n/3: " << std::endl;
    p3.generateTasks(tasks, max_p,min_p, common_seed);
    p3.PTAS(2*tasks/3);
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;

    std::cout << "PTAS 3n/4: " << std::endl;
    p3.generateTasks(tasks, max_p,min_p, common_seed);
    p3.PTAS(3*tasks/4);
    p3.display();
    std::cout << "Cmax: " << p3.calc_Cmax() << std::endl << std::endl;
}

void P2_test1() {
    int common_seed = 1;
    ProblemP2 p2;
    int tasks = 50;
    int max_p = 200;
    int min_p = 50;

    std::cout << "LSA: " << std::endl;
    p2.generateTasks(tasks, max_p, min_p,common_seed);
    p2.LSA();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "LPT: " << std::endl;
    p2.generateTasks(tasks, max_p, min_p,common_seed);
    p2.LPT();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "PD: " << std::endl;
    p2.generateTasks(tasks, max_p, min_p,common_seed);
    p2.PD();
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    // std::cout << "PZ: " << std::endl;
    // p2.generateTasks(tasks, max_p, min_p,common_seed);
    // p2.PZ();
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    // std::cout << "PTAS: " << std::endl;
    // p2.generateTasks(tasks, max_p,min_p, common_seed);
    // p2.PTAS(5);
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;
    //
    // std::cout << "FPTAS: " << std::endl;
    // p2.generateTasks(tasks, max_p,min_p, common_seed);
    // p2.FPTAS(3);
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;
}
void P2_test2() {
    int common_seed = 1;
    ProblemP2 p2;
    int tasks = 50;
    int max_p = 100;
    int min_p = 50;

    // std::cout << "PTAS n/2: " << std::endl;
    // p2.generateTasks(tasks, max_p,min_p, common_seed);
    // p2.PTAS(tasks/2);
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    // std::cout << "PTAS 2n/3: " << std::endl;
    // p2.generateTasks(tasks, max_p,min_p, common_seed);
    // p2.PTAS(2*tasks/3);
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    // std::cout << "PTAS 3n/4: " << std::endl;
    // p2.generateTasks(tasks, max_p,min_p, common_seed);
    // p2.PTAS(3*tasks/4);
    // p2.display();
    // std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "FPTAS 2: " << std::endl;
    p2.generateTasks(tasks, max_p,min_p, common_seed);
    p2.FPTAS(2);
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "FPTAS 3: " << std::endl;
    p2.generateTasks(tasks, max_p,min_p, common_seed);
    p2.FPTAS(3);
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;

    std::cout << "FPTAS 4: " << std::endl;
    p2.generateTasks(tasks, max_p,min_p, common_seed);
    p2.FPTAS(4);
    p2.display();
    std::cout << "Cmax: " << p2.calc_Cmax() << std::endl << std::endl;
}