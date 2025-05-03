#include "ProblemP3.h"

void ProblemP3::display() {
    std::cout << "Tasks" << std::endl;
    for (const Task& task : tasks) {
        std::cout<<task.p<<" ";
    }
    std::cout<<std::endl;
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

    for (const Task& task : machine3) {
        std::cout << "|";
        for (int i = 0; i < task.p; ++i) {
            std::cout << "-";
        }
    }
    std::cout << "|" << std::endl;
}
void ProblemP3::generateTasks(int n_tasks, int max_p, int min_p,int seed) {
    tasks.clear();
    machine1.clear();
    machine2.clear();
    machine3.clear();
    tasks.reserve(n_tasks);
    machine1.reserve(n_tasks);
    machine2.reserve(n_tasks);
    machine3.reserve(n_tasks);

    if(seed == 0) seed = std::time(nullptr);
    std::srand(seed);

    for (int i = 0; i < n_tasks; ++i) {
        tasks.emplace_back(i, (std::rand() % (max_p-min_p)) + min_p);
    }
}
int ProblemP3::calc_Cmax(){
    int sum_m1 = 0, sum_m2 = 0,sum_m3=0;

    for(const Task& task : machine1){
        sum_m1 += task.p;
    }
    for(const Task& task : machine2){
        sum_m2 += task.p;
    }
    for(const Task& task : machine3){
        sum_m3 += task.p;
    }

    return std::max(std::max(sum_m1, sum_m2),sum_m3);
}

void ProblemP3::PD(){
    std::chrono::time_point<std::chrono::steady_clock> start0 = std::chrono::steady_clock::now();
    int sum_of_p = 0;
    for(const Task& task : tasks) sum_of_p += task.p;

    int n_rows = static_cast<int>(tasks.size()+1);
    int n_cols = (sum_of_p)+ 1;

    std::vector<std::vector<std::vector<bool>>> T(n_rows, std::vector<std::vector<bool>>(n_cols, std::vector<bool>(n_cols, false)));
    std::vector<std::vector<std::vector<int>>> from(n_rows, std::vector<std::vector<int>>(n_cols, std::vector<int>(n_cols, 0)));

    for (int j = 0; j < n_rows; ++j)
        for (int k = 0; k < n_cols; ++k)
            for (int l = 0; l < n_cols; ++l) {
                T[j][k][l] = false;
                from[j][k][l] = 0;
            }
    for (int j = 0; j < n_rows; ++j) T[j][0][0] = true;

    for(int j = 1; j < n_rows; ++j){
        int p = tasks[j-1].p;
        for(int k = 0; k < n_cols; ++k){
            for(int l = 0; l < n_cols; ++l){
                if (k >= p && T[j - 1][k - p][l]) {
                    T[j][k][l] = true;
                    from[j][k][l] = 1;
                }
                else if (l >= p && T[j - 1][k][l - p]) {
                    T[j][k][l] = true;
                    from[j][k][l] = 2;
                }
                else if (T[j - 1][k][l]) {
                    T[j][k][l] = true;
                    from[j][k][l] = 3;
                }
            }
        }
    }

    int best_max = sum_of_p;
    int best_k = 0, best_l = 0;

    for (int k = 0; k < n_cols; ++k) {
        for (int l = 0; l < n_cols; ++l) {
            if (T[n_rows-1][k][l]) {
                int m3 = sum_of_p - k - l;
                int curr_max = std::max({k, l, m3});
                if (curr_max < best_max) {
                    best_max = curr_max;
                    best_k = k;
                    best_l = l;
                }
            }
        }
    }
    std::cout << "Best max = " <<best_max<< std::endl;
    std::cout << "Best K = " << best_k << std::endl;
    std::cout << "Best L = " << best_l << std::endl;

    for (int j = n_rows-1; j >= 1; --j) {
        int which_machine = from[j][best_k][best_l];
        if (which_machine == 1) {
            machine1.push_back(tasks[j - 1]);
            best_k -= tasks[j - 1].p;
        } else if (which_machine == 2) {
            machine2.push_back(tasks[j - 1]);
            best_l -= tasks[j - 1].p;
        } else {
            machine3.push_back(tasks[j - 1]);
        }
    }
    std::chrono::time_point<std::chrono::steady_clock> end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end0 - start0;
    std::cout<<"Time for PD:"<<elapsed_seconds.count()<<"\n";
}
void ProblemP3::PZ(int max_tasks) {
    std::chrono::time_point<std::chrono::steady_clock> start0 = std::chrono::steady_clock::now();
    if (tasks.empty()) return;

    std::vector<int> m_tasks;
    std::vector<int> best_m_tasks;

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
            if (m_tasks[i] == 2) c3 += tasks[i].p;
        }
        cmax = std::max(c1, std::max(c2, c3));

        //Zapisywanie najlepszego wariantu
        if (cmax < best_cmax){
            best_cmax = cmax;
            best_m_tasks = m_tasks;
        }

        int i = n_tasks - 1;
        while (i >= 0 && m_tasks[i] == 2) {
            m_tasks[i] = 0;
            --i;
        }
        if (i < 0) break; // koniec kombinacji
        ++m_tasks[i];
    }

    //Ustawianie najlepszego rozwiązania
    for (int i = 0; i < n_tasks; ++i) {
        if (best_m_tasks[i] == 0) machine1.push_back(tasks[i]);
        else if (best_m_tasks[i] == 1) machine2.push_back(tasks[i]);
        else machine3.push_back(tasks[i]);
    }
    std::chrono::time_point<std::chrono::steady_clock> end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end0 - start0;
    std::cout<<"Time for PZ:"<<elapsed_seconds.count()<<"\n";
}
void ProblemP3::PTAS(int k){
    std::chrono::time_point<std::chrono::steady_clock> start0 = std::chrono::steady_clock::now();
    std::sort(tasks.begin(), tasks.end(), [](Task a, Task b){ return a.p > b.p; });
    PZ(k);

    int end_m1 = 0, end_m2 = 0;
    for(auto & t : machine1) end_m1 += t.p;
    for(auto & t : machine2) end_m2 += t.p;

    for(int n_tasks = static_cast<int>(tasks.size()); k < n_tasks; ++k){
        if(end_m1 <= end_m2){
            machine1.push_back(tasks[k]);
            end_m1 += tasks[k].p;
        } else {
            machine2.push_back(tasks[k]);
            end_m2 += tasks[k].p;
        }
    }
    std::chrono::time_point<std::chrono::steady_clock> end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end0 - start0;
    std::cout<<"Time for PTAS:"<<elapsed_seconds.count()<<"\n";
}