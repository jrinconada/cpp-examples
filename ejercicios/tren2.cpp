#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

struct Stop {
    string name;
    mutex m;
    Stop(string name) : name(name) {}
};

struct Train {
    string name;
    vector<Stop*> stops;
    
    Train(string name) : name(name) {}

    void go() {
        for (size_t i = 0; i < stops.size(); i++) {
            std::cout << name + " esperando " + stops[i]->name + '\n';
            lock_guard<mutex> guard(stops[i]->m);
            std::cout << name + " parado " + stops[i]->name + '\n';
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
};

void start(Train* t) {
    t->go();
}

int main() {
    Stop* s1 = new Stop("a");
    Stop* s2 = new Stop("b");
    Stop* s3 = new Stop("c");
    Train* t1 = new Train("1");
    Train* t2 = new Train("2");
    t1->stops.push_back(s1);
    t1->stops.push_back(s2);
    t2->stops.push_back(s1);
    t2->stops.push_back(s3);

    thread th1(start, t1);
    thread th2(start, t2);
    th1.join();
    th2.join();
}
