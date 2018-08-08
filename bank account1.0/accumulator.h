#endif                   //__ACCUMULATOR_H__
#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__
#include"date.h"
class Accumulator {
private:
	Date lastDate;
	double value;
	double sum;
public:
	double getSum(const Date &date)const {
		return sum + value * (date - lastDate);
	}
};
#endif // !__ACCUMULATOR_H__

