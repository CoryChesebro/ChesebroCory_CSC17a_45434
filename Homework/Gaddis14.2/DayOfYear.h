#include <string>

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear {
public:
    DayOfYear();
    DayOfYear(int);
    virtual ~DayOfYear();
    
    void setDay();
    void print();
    void calcDate();
    
private:
    int day;
    int mDay;
    
    static std::string months[12];
    static int daysMonths[12];
    
    std::string month;

};

#endif /* DAYOFYEAR_H */

