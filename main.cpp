// Programmer: Timothy Wacker
#include <iostream>
#include "date.h"

using namespace std;

// Test function to print date
void test(const string& description, const Date& d) {
    cout << description << ": " << d.printNumeric() << endl;
}

int main() {
    // Test constructors and setDate method
    Date defaultDate;
    test("Test default constructor", defaultDate);

    Date validDate(2, 28, 2009);
    test("Test constructor with valid date", validDate);

    Date invalidMonth(45, 2, 2009);
    test("Test constructor with invalid month (45, 2, 2009)", invalidMonth);

    Date invalidDay(2, 29, 2009);
    test("Test constructor with invalid day (2, 29, 2009)", invalidDay);

    Date d1;
    d1.setDate(13, 15, 2000);
    test("setDate with bad month (13)", d1);

    d1.setDate(4, 31, 2009);
    test("setDate with bad day (4, 31, 2009)", d1);

    d1.setDate(2, 29, 2009);
    test("leap year with bad date (2, 29, 2009)", d1);

    d1.setDate(2, 29, 2008);
    test("leap year with good date (2, 29, 2008)", d1);

    cout << "print formats:\n";
    cout << d1.printLong() << endl;
    cout << d1.printDayFirst() << endl;

    return 0;
}