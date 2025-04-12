// Programmer: Timothy Wacker

#include "date.h"
#include <iostream>
#include <sstream>

using namespace std;

// initialize the Date object
Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

//  check if a date is valid
bool Date::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12) return false;  
    int maxDay = lastDay(m, y);         
    if (d < 1 || d > maxDay) return false;  
    return true;
}

//  set the date after validation
void Date::setDate(int m, int d, int y) {
    if (m < 1 || m > 12) {
        cout << "Month invalid" << endl;
        month = 1; day = 1; year = 1900;
        return;
    }
    int maxDay = lastDay(m, y);
    if (d < 1 || d > maxDay) {
        cout << "Day invalid" << endl;
        month = 1; day = 1; year = 1900;
        return;
    }
    month = m; day = d; year = y;
}

// check if the current year is a leap year
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

// overload function 
bool Date::isLeapYear(int y) const {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

// get the last day of the current month
int Date::lastDay() const {
    return lastDay(month, year);
}


int Date::lastDay(int m, int y) const {
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y)) return 29;  // February in a leap year
    return daysInMonth[m - 1];
}


string Date::printNumeric() const {
    ostringstream out;
    out << month << "/" << day << "/" << year;
    return out.str();
}


string Date::printLong() const {
    string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    ostringstream out;
    out << monthNames[month - 1] << " " << day << ", " << year;
    return out.str();
}


string Date::printDayFirst() const {
    string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    ostringstream out;
    out << day << " " << monthNames[month - 1] << " " << year;
    return out.str();
}