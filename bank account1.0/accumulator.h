#ifndef __ACCMULATOR_H__
#define __ACCMULATOR_H__
#include"date.h"
class Accumulator{
private:
	Date lastDate;
	double value;		//current value
	double sum;			//the sum of values by day
public:
	//constructor,date is the beginning date of accumulation
	//value is the initial value
	Accumulator(const Date &date,double value):lastDate(date),value(value),sum(0){}
	//get the cumulative result of the date
	double getSum(const Date &date) const{
		return sum+value*date.distance(lastDate);
	}
	//change value in date to value
	void change(const Date &date,double value){
		sum=getSum(date);
		lastDate=date;
		this->value=value;
	}
	//initialization
	void reset(const Date &date,double value){
		lastDate=date;
		this->value=value;
		sum=0;
	}
};
#endif                   //__ACCUMULATOR_H__
