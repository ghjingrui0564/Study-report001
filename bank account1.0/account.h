#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include"date.h"
#include"accumulator.h"
#include<string>

class Account {
private:
	std::string id;
	double balance;
	static double total;
protected:
	Account(const Date &date, const std::string &id);
	void record(const Date &date, double amount, const std::string &desc);
	void error(const std::string &msg)const;
public:
	const std::string &getId()const { return id; }
	double getBalance()const { return balance; }
	static double getTotal() { return total; }
	virtual void deposit(const Date &date, double amount, const std::string &desc) = 0;
	virtual void withdraw(const Date &date, double amount, const std::string &desc) = 0;
	virtual void settle() { const Date &date } = 0;
	virtual void show()const;
};
#endif // !__ACCOUNT_H__
