/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

//int main(void)
//{
//    cout << endl;
//    //cout << "Running 'SELECT 'Hello World!' » AS _message'..." << endl;
//
//    try {
//        sql::Driver* driver;
//        sql::Connection* con;
//        sql::Statement* stmt;
//        sql::ResultSet* res;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        con = driver->connect("tcp://127.0.0.1:3306", "root", "kanchan");
//        /* Connect to the MySQL test database */
//        con->setSchema("bankdb");
//
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery("SELECT * from accounts");
//        while (res->next()) {
//      
//            /* Access column data by alias or column name */
//            cout << "\n";
//            cout << "AccountNumber: " << res->getInt(1) << "\n ";
//            cout << "FirstName: " << res->getString(2) << "\n ";
//            cout << "LastName: " << res->getString(3) << "\n ";
//            cout << "Gender: " << res->getString(4) << "\n ";
//            cout << "Address: " << res->getString(5) << "\n ";
//            cout << "Balance: " << res->getString(6) << "\n ";
//            cout << "City: " << res->getString(7) << "\n ";
//            cout << "AccountType: " << res->getString(8) << "\n";
//            cout << "DateOfJoin: " << res->getString(9) << endl;
//            /* Access column data by numeric offset, 1 is the first column */
//           // cout << res->getString(1) << endl;
//        }
//        stmt = con->createStatement();
//        res = stmt->executeQuery("insert into accounts (FirstName, LastName, Gender, Address, Balance, City, AccountType) values ('Zakir','Khan','male','345 noida','6000','ghaziabad','saving')");
//        delete res;
//        delete stmt;
//        delete con;
//
//    }
//    catch (sql::SQLException& e) {
//        cout << "# ERR: SQLException in " << __FILE__;
//
//        cout << "# ERR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//    }
//
//    cout << endl;
//
//    return EXIT_SUCCESS;
//}


//#include<iostream>
//#include<string>
class bankSystem
{
private:
	std::string name;
	int accountNo;
	int balance = 0;
	std::string address;
public:
	void Create(std::string nam, int accNo, std::string addres)
	{
		name = nam;
		accountNo = accNo;
		address = addres;
		ShowBalance();
	}
	void ShowBalance()
	{

		std::cout << "\nName:" << name;
		std::cout << "\nAccount No:" << accountNo;
		std::cout << "\nbalance" << balance;

	}
	bool Verify(int accountN)
	{
		if (accountNo == accountN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Withdraw(int amount)
	{
		balance = balance - amount;
	}
	void Deposit(int damount)
	{
		balance = balance + damount;
	}
};
int main()
{
	sql::Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	sql::ResultSet* res = NULL;
	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "kanchan");
	/* Connect to the MySQL test database */
	con->setSchema("bankdb");

	int choice;
	//bankSystem list[10]; int i; 
	int accono1; int accono2;
	bankSystem obj;
	int sno = 0;
	while (1 == 1)
	{
		std::cout << "\nenter 1 to create account" << "\n";
		std::cout << "enter 2 to see balance" << "\n";
		std::cout << "enter 3 to withdraw" << "\n";
		std::cout << "enter 4 to deposit" << "\n";
		std::cout << "enter 5 to View All" << "\n";
		std::cout << "enter 6 to transfer money" << "\n";
		std::cout << "enter 7 to View All Accout" << "\n";
		std::cout << "enter 8 to exit" << "\n";
		std::cout << "enter your choice" << "\n";
		std::cin >> choice;
		int amount; std::string accno; std::string ben ; bool isFound; int bal;
		switch (choice)
		{
		case 1:
		{ std::string na; std::string ad; std::string lna, gender;
		std::cout << "enter your Fname" << "\n";
		std::cin >> na;
		std::cout << "enter your lname" << "\n";
		std::cin >> lna;
		std::cout << "enter your lname" << "\n";
		std::cin >> gender;
		std::cout << "enter your address" << "\n";
		std::cin >> ad;
		stmt = con->createStatement();
		stmt->executeUpdate("insert into accounts (FirstName, LastName, Gender, Address, Balance, City, AccountType) values ('" + na + "','" + lna + "','" + gender + "','" + ad + "','0','ghaziabad','saving')");
		//        
		//sno++;

		//Insert Query
		// 
		//obj.Create(na, 1000 + sno, ad);
		//list[sno - 1] = obj;
		//obj.ShowBalance();
		}
		break;
		case 2:
			//sql::ResultSet* res2 = NULL;
			std::cout << "enter your account number" << "\n";
			std::cin >> accno;
			stmt = con->createStatement();

			res = stmt->executeQuery("SELECT * from accounts where accountNumber='" + accno +"'");
			while (res->next()) {

				/* Access column data by alias or column name */
				cout << "\n";
				cout << "AccountNumber: " << res->getInt(1) << "\n ";
				cout << "FirstName: " << res->getString(2) << "\n ";
				cout << "LastName: " << res->getString(3) << "\n ";

				cout << "Balance: " << res->getString(6) << "\n ";

				/* Access column data by numeric offset, 1 is the first column */
			   // cout << res->getString(1) << endl;
			}
			break;

		case 3:

			std::cout << "enter the account number" << "\n";
			std::cin >> accno;
			std::cout << "enter the amount" << "\n";
			std::cin >> amount;
			stmt = con->createStatement();
			//int bala;
			res = stmt->executeQuery("SELECT * from accounts where accountNumber='" + accno + "'");
			while (res->next()) {
				bal = res->getInt(6);
			cout <<"current bal:" << bal<<"\n";
				std::string cbal= to_string(bal - amount);
				cout << cbal;
				stmt->executeUpdate("update accounts set Balance='"+ cbal +"' where accountNumber='"+ accno +"'");
			}
			/*for (i = 0; i <= sno; i++)
			{
				isFound = list[i].Verify(accno);
				if (isFound)
				{
					std::cout << "enter the amount to withdraw" << "\n";
					std::cin >> amount;
					list[i].Withdraw(amount);
				}
			}*/
			break;
		case 4:

			std::cout << "enter the account number" << "\n";
			std::cin >> accno;
			std::cout << "enter the amount" << "\n";
			std::cin >> amount;
			stmt = con->createStatement();
			int bal;
			res = stmt->executeQuery("SELECT * from accounts where accountNumber='" + accno + "'");
			while (res->next()) {
				bal = res->getInt(6);
				cout << "current bal:" << bal << "\n";
				std::string cbal = to_string(bal + amount);
				cout << cbal;
				stmt->executeUpdate("update accounts set Balance='" + cbal + "' where accountNumber='" + accno + "'");
			}
			/*for (i = 0; i <= sno; i++)
			{
				isFound = list[i].Verify(accno);
				if (isFound)
				{
					std::cout << "enter the amount to be deposit" << "\n";
					std::cin >> amount;
					list[i].Deposit(amount);
				}
			}*/

			break;
		case 5:
			std::cout << "number of account" << sno;
			/*for (i = 0; i <= sno - 1; i++)
			{
				list[i].ShowBalance();
			}*/
			break;
		case 6:
			
			std::cout << "enter the account number from which you want to transfer money";
			std::cin >> accno;
			std::cout << "enter the amount to transfer" << "\n";
			std::cin >> amount;
			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * from accounts where accountNumber='" + accno + "'");
			while (res->next()) {
				bal = res->getInt(6);
				cout << "current bal:" << bal << "\n";
				std::string cbal = to_string(bal - amount);
				cout << cbal;
				stmt->executeUpdate("update accounts set Balance='" + cbal + "' where accountNumber='" + accno + "'");
			}
			std::cout << "enter the account number to which you want to transfer money";
			std::cin >> ben;
			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * from accounts where accountNumber='" + ben + "'");
			while (res->next()) {
				bal = res->getInt(6);
				cout << "current bal:" << bal << "\n";
				std::string cbal = to_string(bal + amount);
				cout << cbal;
				stmt->executeUpdate("update accounts set Balance='" + cbal + "' where accountNumber='" + accno + "'");
			}
			//std::cout << "enter the amount you want to transfer" << "\n";
		//	std::cin >> amount;
			/*for (i = 0; i < sno; i++)
			{
				isFound = list[i].Verify(accono1);
				if (isFound)
				{
					list[i].Withdraw(amount);
				}
			}
			for (i = 0; i < sno; i++)
			{
				isFound = list[i].Verify(accono2);
				if (isFound)
				{
					list[i].Deposit(amount);
				}
			}*/
			break;
		case 8:
			delete res;
			delete stmt;
			delete con;
			exit(0);
			break;

		case 7:
			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * from accounts");
			while (res->next()) {

				/* Access column data by alias or column name */
				cout << "\n";
				cout << "AccountNumber: " << res->getInt(1) << "\n ";
				cout << "FirstName: " << res->getString(2) << "\n ";
				cout << "LastName: " << res->getString(3) << "\n ";
				cout << "Gender: " << res->getString(4) << "\n ";
				cout << "Address: " << res->getString(5) << "\n ";
				cout << "Balance: " << res->getString(6) << "\n ";
				cout << "City: " << res->getString(7) << "\n ";
				cout << "AccountType: " << res->getString(8) << "\n";
				cout << "DateOfJoin: " << res->getString(9) << endl;
				/* Access column data by numeric offset, 1 is the first column */
			   // cout << res->getString(1) << endl;
			}
			delete res;
			delete stmt;
			break;
		}
	}
	delete res;
	delete stmt;
	delete con;
}
