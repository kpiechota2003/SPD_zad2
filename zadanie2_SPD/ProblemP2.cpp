#include "ProblemP2.h"

void ProblemP2::display() {
    for (const Task& task : machine1) {
        std::cout << "|";
        for (int i = 0; i < task.p; ++i) {
            std::cout << "-";
        }
    }
    std::cout << "|" << std::endl;

    for (const Task& task : machine2) {
        std::cout << "|";
        for (int i = 0; i < task.p; ++i) {
            std::cout << "-";
        }
    }
    std::cout << "|" << std::endl;
}

void ProblemP2::generateTasks(int n_tasks, int max_p, int seed) {
    tasks.clear();
    machine1.clear();
    machine2.clear();
    tasks.reserve(n_tasks);
    machine1.reserve(n_tasks);
    machine2.reserve(n_tasks);

    if(seed == 0) seed = std::time(nullptr);
    std::srand(seed);

    for (int i = 0; i < n_tasks; ++i) {
        tasks.emplace_back(i, (std::rand() % max_p) + 1);
    }
}

int ProblemP2::calc_Cmax(){
    int sum_m1 = 0, sum_m2 = 0;

    for(const Task& task : machine1){
        sum_m1 += task.p;
    }
    for(const Task& task : machine2){
        sum_m2 += task.p;
    }

    return std::max(sum_m1, sum_m2);
}

void ProblemP2::LSA(){
    int end_m1 = 0, end_m2 = 0;
    machine1.clear();
    machine2.clear();

    for(const Task& task : tasks){
        if(end_m1 <= end_m2){
            machine1.push_back(task);
            end_m1 += task.p;
        } else {
            machine2.push_back(task);
            end_m2 += task.p;
        }
    }
}

void ProblemP2::LPT(){
    std::sort(tasks.begin(), tasks.end(), [](Task a, Task b){ return a.p > b.p; });
    LSA();
}

void ProblemP2::PD(){
    int sum_of_p = 0;
    for(const Task& task : tasks) sum_of_p += task.p;

    int n_rows = static_cast<int>(tasks.size() + 1);
    int n_cols = sum_of_p / 2 + 1;

    int** T = new int*[n_rows](); // () zapewnia wypełnienie zerami

    for (int j = 0; j < n_rows; ++j) {
        T[j] = new int[n_cols](); // tu też wypełnia zerami
        T[j][0] = 1; //pierwsza kolumna uzupelniona jedynkami
    }

    // algorytm programowania dynamicznego z instrukcji
    for(int j = 1; j < n_rows; ++j){
        for(int k = 1; k < n_cols; ++k){
            if((T[j - 1][k] == 1) || ((k >= tasks[j].p) && (T[j - 1][k - tasks[j].p] == 1))) T[j][k] = 1;
        }
    }

    int c = 0, cmax = INT32_MAX, k_cmax = 0;

    for(int k = 1; k < n_cols; ++k){
        if(T[n_rows - 1][k] == 1){
            c = std::max(k, sum_of_p - k);
            if (c < cmax) {
                cmax = c;
                k_cmax = k;
            }
        }
    }

    for (int j = n_rows - 1; j >= 1; --j){
        if((k_cmax >= tasks[j - 1].p) && (T[j - 1][k_cmax - tasks[j - 1].p] == 1)){
            machine1.push_back(tasks[j - 1]);
            k_cmax -= tasks[j - 1].p;
        } else {
            machine2.push_back(tasks[j - 1]);
        }
    }

/*
    //debug display
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            std::cout << T[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/

    for (int i = 0; i < n_rows; ++i) {
        delete[] T[i];
    }
    delete[] T;
}

void ProblemP2::PZ() {
    if (tasks.empty()) return;

    std::vector<bool> m1_tasks;
    std::vector<bool> best_m1_tasks;
    auto it = m1_tasks.end();

    int n_tasks = tasks.size(), cmax = 0, best_cmax = INT_MAX, sum_of_p = 0;
    for (auto &task: tasks) sum_of_p += task.p;

    m1_tasks.resize(n_tasks);
    best_m1_tasks.resize(n_tasks);

    for (int i = 0; i < n_tasks; ++i) m1_tasks[i] = false;


    while (!m1_tasks[0]) {
        //Liczenie Cmax
        cmax = 0;
        for (int i = 0; i < n_tasks; ++i) {
            if (m1_tasks[i]) cmax += tasks[i].p;
        }
        cmax = std::max(cmax, sum_of_p - cmax);

        //Zapisywanie najlepszego wariantu
        if (cmax < best_cmax){
            best_cmax = cmax;
            best_m1_tasks = m1_tasks;
        }

        //Zwieksz o 1
        it = (m1_tasks.end())--;
        while (true) {
            *it = !*it;
            if (*it) break;
            --it;
        }
    }

    //Ustawianie najlepszego rozwiązania
    for (int i = 0; i < n_tasks; ++i) {
        if (best_m1_tasks[i]) machine1.push_back(tasks[i]);
        else machine2.push_back(tasks[i]);
    }
}