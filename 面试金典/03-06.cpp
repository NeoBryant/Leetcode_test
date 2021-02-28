#include <iostream>
#include <vector>

using namespace std;

// 用两个队列分别存储猫和狗，其编号表示其进入收容所的时间

class AnimalShelf {
private:
    vector<vector<int> > cats;
    vector<vector<int> > dogs;
    int cat, dog;
public:
    AnimalShelf() { 
        cat = 0;
        dog = 1;
    }
    
    void enqueue(vector<int> animal) {
        // queue.push_back(animal);
        if (animal[1] == cat) {
            cats.push_back(animal);
        } else {
            dogs.push_back(animal);
        }
    }
    
    vector<int> dequeueAny() {
        vector<int> result(2, -1);
        if (cats.size() == 0 && dogs.size() != 0) {
            result = dogs[0];
            dogs.erase(dogs.begin());
        } else if (cats.size() != 0 && dogs.size() == 0) {
            result = cats[0];
            cats.erase(cats.begin());
        } else if (cats.size() != 0 && dogs.size() != 0) {
            if (cats[0][0] < dogs[0][0]) {
                result = cats[0];
                cats.erase(cats.begin());
            } else {
                result = dogs[0];
                dogs.erase(dogs.begin());
            }
        }
        return result;
    }
    
    vector<int> dequeueDog() {
        vector<int> result(2, -1);
        if (dogs.size() > 0) {
            result = dogs[0];
            dogs.erase(dogs.begin());
        }
        return result;
    }
    
    vector<int> dequeueCat() {
        vector<int> result(2, -1);
        if (cats.size() > 0) {
            result = cats[0];
            cats.erase(cats.begin());
        }
        return result;
    }
};

int main() {
    AnimalShelf a;
    vector<int> b;
    b.push_back(0);
    b.push_back(0);
    vector<int> c;
    c.push_back(1);
    c.push_back(0);
    
    a.enqueue(b);
    a.enqueue(c);
    
    cout << a.dequeueCat()[0] << endl;
    cout << a.dequeueDog()[0] << endl;
    cout << a.dequeueAny()[0] << endl;

    return 0;
}