//
// Created by Francesco on 2019-08-05.
//

#include "User.h"


User::User(std::string fn, std::string sn): firstName(fn), secondName(sn), account(nullptr) {}

User::~User() {

    delete account;
}


bool User::createAccount(const std::string userName, const std::string password) {

    if(account != nullptr){
        return false;
    }

    account=new Account(userName, password);
    return true;

}

Account& User::logIn( const std::string userName, const std::string password) {

    if(account != nullptr){

        if(account->checkCredentials(userName, password))
            return *account;

        throw not_found("Account", userName);
    }

    throw  not_found("Account", userName);


}


void User::deleteAccount(const std::string userName, const std::string password) {

    if(account != nullptr) {

        if (account->checkCredentials(userName, password)) {

            delete account;
            account = nullptr;

        }
    }

}

bool User::createAccount(const std::string password) {

    if(account != nullptr){
        return false;
    }

    account=new Account(defaultUserNameGenerator(), password);
    return true;

}


const std::string User::defaultUserNameGenerator() {

    std::string userName="";
    userName.push_back(firstName[0]);
    userName.push_back(secondName[0]);
    userName+= "." + firstName + secondName;

    return userName;
}