#include "ProblemP3.h"

void ProblemP3::PZ(int max_tasks) {
    if (tasks.empty()) return;

    std::vector<int> m_tasks;
    std::vector<int> best_m_tasks;
    auto it = m_tasks.end();

    int n_tasks, cmax = 0, best_cmax = INT_MAX, sum_of_p = 0;
    for (auto &task: tasks) sum_of_p += task.p;
    if(max_tasks < 0) n_tasks = tasks.size();
    else n_tasks = std::min(max_tasks, static_cast<int>(tasks.size()));

    m_tasks.resize(n_tasks);
    best_m_tasks.resize(n_tasks);

    for (int i = 0; i < n_tasks; ++i) m_tasks[i] = 0;


    while (m_tasks[0] == 0) {
        //Liczenie Cmax
        int c1 = 0, c2 = 0, c3 = 0, cmax = 0;
        for (int i = 0; i < n_tasks; ++i) {
            if (m_tasks[i] == 0) c1 += tasks[i].p;
            if (m_tasks[i] == 1) c2 += tasks[i].p;
            if (m_tasks[i] == 0) c1 += tasks[i].p;
        }
        cmax = std::max(c1, std::max(c2, c3));

        //Zapisywanie najlepszego wariantu
        if (cmax < best_cmax){
            best_cmax = cmax;
            best_m_tasks = m_tasks;
        }

        //Zwieksz o 1
        it = (m_tasks.end())--;
        while (true) {
            if(*it < 2) ++*it;
            else break;
            --it;
        }
    }

    //Ustawianie najlepszego rozwiązania
    for (int i = 0; i < n_tasks; ++i) {
        if (best_m_tasks[i] == 0) machine1.push_back(tasks[i]);
        else if (best_m_tasks[i] == 1) machine2.push_back(tasks[i]);
        else machine3.push_back(tasks[i]);
    }
}