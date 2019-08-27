//
// Created by Francesco on 2019-08-02.
//

#ifndef CHATPROJECT_ACCOUNT_H
#define CHATPROJECT_ACCOUNT_H

#include <iostream>
#include "ChatList.h"


class Account {
public:
    Account(std::string un, std::string pass);

    Chat& inviteToChat(const std::string friendName);
    void removeChat(const std::string friendName);
    Chat& chatWith(const std::string friendName);
    std::string shareContact() const;
    bool checkCredentials(const std::string us, const std::string pass) const;
    bool operator == (const Account& right) const;

private:
    std::string username, password;
    ChatList chatList;
};


#endif //CHATPROJECT_ACCOUNT_H
