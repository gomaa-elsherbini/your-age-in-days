#include <iostream>
#include <ctime>
using namespace std;



struct stDate
{
    short day;
    short month;
    short year;
};

short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

stDate readStDate()
{
    stDate Date;

    Date.day = readNumber("Please Enter a Day ");
    Date.month = readNumber("Please Enter a Month ");
    Date.year = readNumber("Please Enter a Year ");

    return Date;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

short numberOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

//bool isDate1BeforeDate2(stDate Date1, stDate Date2)
//{
//    //return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? ((Date1.month < Date2.month) ? true : ((Date1.month == Date2.month) ? ((Date1.day < Date2.day) ? true : false) : false)) : false);
//    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? (Date1.day < Date2.day) : false)) : false);
//}
//
//bool isDayIsLastDay(stDate Date)
//{
//    return Date.day == numberOfDaysInMonth(Date.year, Date.month);
//}
//
//bool isMonthIsLastMonth(stDate Date)
//{
//    return Date.month == 12;
//}
//
//stDate increaseDateByOneDay(stDate Date)
//{
//    if (isDayIsLastDay(Date))
//    {
//        if (isMonthIsLastMonth(Date))
//        {
//            Date.month = 1;
//            Date.year++;
//        }
//        else
//            Date.month++;
//
//        Date.day = 1;
//    }
//    else
//        Date.day++;
//
//    return Date;
//}

stDate getSystmfDate()
{
    stDate sysDate;
    
    time_t t = time(0);
    //tm* now = localtime(&t);
    tm* now = localtime(&t);

    sysDate.year = now->tm_year + 1900;
    sysDate.month = now->tm_mon + 1;
    sysDate.day = now->tm_mday;

    return sysDate;
}

int ageInDays(stDate DateOfBirth, stDate Date2, bool isIncludeEndDay = false)
{
    int numberOfDays = 0;

    for (short year = DateOfBirth.year; year < Date2.year; year++)
        numberOfDays += numberOfDaysInYear(year);

    for (short month = DateOfBirth.month; month < Date2.month; month++)
        numberOfDays += numberOfDaysInMonth(DateOfBirth.year, month);

    numberOfDays += Date2.day - DateOfBirth.day;

    /*while (isDate1BeforeDate2(DateOfBirth, Date2))
    {
        numberOfDays++;
        DateOfBirth = increaseDateByOneDay(DateOfBirth);
    }*/

    return (isIncludeEndDay) ? ++numberOfDays : numberOfDays;
}





int main()
{
    stDate DateOfBirth, currentDate;

    cout << "Please Enter your date of Birth\n";
    DateOfBirth = readStDate();
    
    cout << "\n";
    cout << "Please Enter the current date\n";
    
    currentDate = getSystmfDate();
    cout << "\n\n";



    cout << "your Age is: " << ageInDays(DateOfBirth, currentDate) << " Day(s).\n";
    //cout << "your Age is: "; dateForNumberOfDays(DateOfBirth.year, ageInDays(DateOfBirth, currentDate));
 


    system("pause>0");
    return main();
}