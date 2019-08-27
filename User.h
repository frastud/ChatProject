//
// Created by Francesco on 2019-08-05.
//

#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H

#include <iostream>
#include "Account.h"



class User {
public:

    User(std::string fn, std::string sn);
    ~User();

    const std::string getFirstName() const { return firstName; }
    const std::string getSecondName() const { return secondName; }
    bool createAccount(const std::string userName, const std::string password);
    bool createAccount(const std::string password);  // create an account with a default username
    const Account& logIn(const std::string userName, const std::string password);
    void deleteAccount(const std::string userName, const std::string password);


private:

    const std::string defaultUserNameGenerator();

    std::string firstName, secondName;
    Account* account;

};



#endif //CHATPROJECT_USER_H
