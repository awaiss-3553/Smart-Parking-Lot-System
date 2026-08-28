#include <iostream>
#include <string>

using namespace std;

// 1. Base Class
class vehical {
public:
    string noplate;
    int totalHours;

    vehical(string noplate, int totalHours) {
        this->noplate = noplate;
        this->totalHours = totalHours;
    }

    // Simple virtual function
    virtual int getfair() {
        return 0;
    }
};

// 2. Car Class
class car : public vehical {
public:
    car(string noplate, int totalHours) : vehical(noplate, totalHours) {}

    int getfair() {
        if (totalHours <= 2) {
            return totalHours * 50;
        } else {
            return (2 * 50) + (totalHours - 2) * 80;
        }
    }
};

// 3. Bike Class
class bike : public vehical {
public:
    int helmetfee = 10;

    bike(string noplate, int totalHours) : vehical(noplate, totalHours) {}

    int getfair() {
        if (totalHours <= 2) {
            return (totalHours * 20) + helmetfee;
        } else {
            return (2 * 20) + (totalHours - 2) * 30 + helmetfee;
        }
    }
};

// 4. Main Program (Direct Simple Objects)
int main() {
    // Direct objects - no new / delete / complex pointers
    car c1("LEA-1234", 4);
    bike b1("LHE-5678", 3);

    cout << "Car No: " << c1.noplate << " | Total Bill: Rs. " << c1.getfair() << endl;
    cout << "Bike No: " << b1.noplate << " | Total Bill: Rs. " << b1.getfair() << endl;

    return 0;
}
