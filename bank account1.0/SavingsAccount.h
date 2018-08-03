//SavingsAccount.h
#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include"account.h"
#include<string>
class SavingsAccount:public Account{
private:
	Accumulator acc;					//an accumulator for calculating interest
	double rate;						//the annual interest on deposits
public:
	//constructor
	SavingsAccount(const Date &date,const std::string &id,double rate);
	double getRate()const {return rate;}
	//action
	void deposit (const Date &date,double amount,const std::string &desc);
	void withdraw(const Date &date,double amount,const std::string &desc);
	void settle(const Date &date);		//calculate interest,it is called once a year on January 1st
};
#endif //_SAVINGSACCOUNT_H_
