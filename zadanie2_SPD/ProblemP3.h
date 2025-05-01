#ifndef ZADANIE2_SPD_PROBLEMP3_H
#define ZADANIE2_SPD_PROBLEMP3_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Task.h"

class ProblemP3 {
public:
    std::vector<Task> tasks;
    std::vector<Task> machine1;
    std::vector<Task> machine2;
    std::vector<Task> machine3;

    ProblemP3()= default;

    //void generateTasks(int n_tasks, int max_p, int seed = 0);
    //int calc_Cmax();

    //void LSA();
    //void PD();
    void PZ(int max_tasks = -1); //przegląd zupełny
    //void PTAS(int k);
    //void FPTAS(int k);

    //void display();
};


#endif //ZADANIE2_SPD_PROBLEMP3_H
