//
// Created by Francesco on 2019-08-05.
//


#include "gtest/gtest.h"
#include "../User.h"
#include "../Account.h"

TEST(User, CreateAccount){

    User alessandro("Alessandro", "Borghese");
    ASSERT_TRUE(alessandro.createAccount("AleChef_76", "******"));
    ASSERT_FALSE(alessandro.createAccount("AlessandroB", "inVinoVeritas"));

}


TEST(User, DefaultUserNameAccount){

    std::string userName="EG.ElisabettaGalli";
    User elisabetta("Elisabetta", "Galli");

    ASSERT_TRUE(elisabetta.createAccount("******"));
    ASSERT_FALSE(elisabetta.createAccount("newPassword"));

    ASSERT_EQ(Account(userName, "******"), elisabetta.logIn("EG.ElisabettaGalli", "******"));

}

TEST(User, LogIn){

    User user("Martina", "BLUcandy");
    user.createAccount("Marty_Casi", "******");
    ASSERT_EQ(Account("Marty_Casi", "******"), user.logIn("Marty_Casi", "******"));

}

TEST(User, DeleteAccount){

    User andrea("Andrea", "Massai");
    ASSERT_TRUE(andrea.createAccount("Andre_95", "******"));

    andrea.deleteAccount("Andre_95", "******");
    ASSERT_TRUE(andrea.createAccount("Andrea_M95", "6151930"));

}

TEST(User, GetFirstName){

    const std::string firstName="Marco";
    User marco(firstName, "Rossi");

    ASSERT_EQ(firstName, marco.getFirstName());

}

TEST(User, GetSecondName){

    const std::string secondName="Rossi";
    User marco("Marco", secondName);

    ASSERT_EQ(secondName, marco.getSecondName());

}
