#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

#include "chef.cpp"

void printTime(std::chrono::system_clock::time_point time) {
	std::time_t timeStamp = std::chrono::system_clock::to_time_t(time);
	std::cout << std::ctime(&timeStamp) << std::endl;
}

void start(Chef c) {
    c.cook();
}

void waiter(vector<future<string>>& futures) {
	for (auto& course : futures) {
		std::cout << "                                                            Llevar " << course.get() << '\n';
	}
}

int main() {
    printTime(std::chrono::system_clock::now());

	Chef c1("Pep", "cutter");
	c1.recipes.push_back(new Recipe("espárragos", 2, 3));
    c1.recipes.push_back(new Recipe("pollo", 1, 2));
	c1.recipes.push_back(new Recipe("pescado", 4, 2));
	c1.recipes.push_back(new Recipe("lasaña", 3, 1));
	Chef c2("                              Ana", "baker");
	c2.recipes = c1.recipes;

	vector<future<string>> futures;
	for (size_t i = 0; i < c1.recipes.size(); i++) {
		futures.push_back(c1.recipes[i]->prom.get_future());
	}

	thread t1(start, c1);
    thread t2(start, c2);
	thread w(waiter, ref(futures));
	t1.join();
    t2.join();
	w.join();

    printTime(std::chrono::system_clock::now());
}
