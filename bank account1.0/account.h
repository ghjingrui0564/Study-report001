//account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include"date.h"
#include"accumulator.h"

#include<string>

class Account{
private:
	std::string id;
	double balance;
	static double total;
protected:
	//a constructor called by a derived class
	Account(const Date &date,const std::string &id);
	void record(const Date &date,double amount,const std::string &desc);
	//report error message 
	void error(const std::string &msg) const;
public:
	const std::string &getId(){return id;}
	double getBalance()const {return balance;}
	static double getTotal(){return total;}
	void show() const;
};
#endif //_ACCOUNT_H_
