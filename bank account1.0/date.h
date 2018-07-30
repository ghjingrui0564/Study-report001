//date.h
#ifndef _DATE_H_
#define _DATE_H_
class Date{
private:
	int year;
	int month;
	int day;
	int totalDays;							//calculations begin on January 1st
public:
	Date(int year,int month,int day);
	int getYear() const{return year;}
	int getMonth() const{return month;}
	int getDay() const{return day;}
	int getMaxDay() const;					//get the number of days of the month
	bool isLeapYear() const{				//determine whether it is a leap year
		return year%4==0 && year%100!=0 || year%400==0;
	}
	void show() const;						//output current date
	int distance(const Date &date) const{
		return totalDays-date.totalDays;
	}
#endif
