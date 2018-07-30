//account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include"date.h"
#include<string>
class SavingsAccount{
private:
	std::string id;
	double balance;
	double rate;							//the annual interest rate on deposits
	Date lastDate;							//date of the last time the balance was changed
	double accumulation;					//the sum of the balances accumulated on a daily basis
	static double total;					//total amount of all accounts
	void record(const Date &date,double amount,const std::string &desc);
	//
	void error(const std::string &msg) const;
	//
	double accumulate(const Date &date) const{
		return accumulation+balance*date.distance(lastDate);
	}
public:
	//the constructor
	SavingsAccount(const Date &date,const std::string &id,double rate);
	const std::string &getId() const {return id;}
	double getBalance() const{return balance}
	double fetRate() const {return rate;}
	static double getTotal(){return total;}
	//deposit money
	void deposit(const Date &date,double amount,const std::string &desc);
	//withdraw money
	void withdraw(const Date &date,double amount,const std::string &desc);
	//settle the interest,this function is called on January 1st every year
	void settle(const Date &date);
	//display account information
	void show() const;
};
#endif
