#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore {
    mutex mu;
    condition_variable condition;
    unsigned int count = 0;
    unsigned int limit;
public:
    Semaphore(unsigned int limit = 1) : count(limit) {}

    void notify() {
        unique_lock<mutex> lock(mu);
        count++;
        condition.notify_one();
    }

    void wait() {
        unique_lock<mutex> lock(mu);
        while(count == 0) {
            condition.wait(lock);
        }
        count--;
    }
};
