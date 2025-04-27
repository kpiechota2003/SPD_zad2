#ifndef ZADANIE2_SPD_TASK_H
#define ZADANIE2_SPD_TASK_H

#include <iostream>

class Task {
public:
    int index = 0;
    int p = 0;

    Task() = default;
    Task(int i, int time_p){ index = i; p = time_p; }

    bool operator<(const Task& other) const {
        return p < other.p;
    }
};

//std::ostream& operator<<(std::ostream& os, const Task& task) {
//    os << "[" << task.index << "] p = (" << task.p << ")";
//    return os;
//}


#endif //ZADANIE2_SPD_TASK_H
