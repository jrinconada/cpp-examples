#include <iostream>
#include <vector>

template <typename T>
class Observer {
public:
    virtual void changed(T& observable, const std::string& attribute) = 0;
};

template <typename T>
class Observable {
    std::vector<Observer<T>*> observers;
public:
    void notify(T& observable, const std::string& attribute) {
        for(auto observer : observers) {
            observer->changed(observable, attribute);
        }
    }
    void subscribe(Observer<T>& observer) {
        observers.push_back(&observer);
    }
    void unsubscribe(Observer<T>& observer) {
        // Borrar un elemento de un vector por valor
        observers.erase(remove(observers.begin(), observers.end(), &observer), observers.end());
    }
};

class Person : public Observable<Person> {
    short age;
public:
    short getAge() {
        return age;
    }

    void setAge(short a) {
        if (a != age) {
            age = a;
            notify(*this, "age");
        }
    }
};

class PersonObserver : public Observer<Person> {
    void changed(Person& observable, const std::string& attribute) override {
        std::cout << attribute << " ha cambiado a " << observable.getAge() << '\n';
        if (observable.getAge() == 18) {
            std::cout << "Ya eres adulto!" << '\n';
        }
    }
};

int main () {
    Person person;
    PersonObserver o;
    person.subscribe(o);

    person.setAge(17);
    person.setAge(18);

    person.unsubscribe(o);

    person.setAge(19);
}
