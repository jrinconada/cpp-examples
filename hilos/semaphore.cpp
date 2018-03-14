#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore {
    mutex mu;
    condition_variable condition;
    unsigned int count;
public:
    Semaphore() : count(0) {}

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
