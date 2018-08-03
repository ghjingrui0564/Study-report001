//SavingsAccount.cpp
#include"SavingsAccount.h"
#include"account.h"
#include<cmath>
#include<iostream>
using namespace std;

SavingsAccount::SavingsAccount(const Date &date,const string &id,double rate)
:Account(date,id),rate(rate),acc(date,0){}

void SavingsAccount::deposit(const Date &date,double amount,const string &desc){
	record(date,amount,desc);
	acc.change(date,getBalance());
}
void SavingsAccount::withdraw(const Date &date,double amount,const string &desc){
	if(amount>getBalance()){
		error("not enough money");
	}else{
		record(date,-amount,desc);
		acc.change(date,getBalance());
	}
}
void SavingsAccount::settle(const Date&date){
	double interest=acc.getSum(date)*rate/date.distance(Date(date.getYear()-1,1,1));
	if(interest!=0) 
		record(date,interest,"interest");
	acc.reset(date,getBalance());
}
