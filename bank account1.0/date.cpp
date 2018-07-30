//date.cpp
#include"date.h"
#include<iostrem>
#include<cstdlib>
using namespace std;
namespace{					//make the following definitions valid only in the current file
	//store the days before the 1st of a month
	const int DAYS_BEFORE_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
}
Date::Date(int year,int month,int day):year(year),month(month),day(day){
	if(day<=0 || day>getMaxDay()){
		cout<<"invalid date:";
		show();
		cout<<endl;
		exit(1);
	}
	int years=year-1;
	totalDays=year*365+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day;
	if(isLeapYear() && month>2) totalDays++;
}
int Date::getMaxDay() const{
	if(isLeapYear() && month==2)
		return 29;
	else
		return DAYS_BEFORE_MONTH[month-1];
}
void Date::show() const{
	cout<<getYear()<<"-"<<getmonth()<<"-"<<getDay();
}
