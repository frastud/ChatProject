//
// Created by Francesco on 2019-08-02.
//

#include "Account.h"


Account::Account(std::string un, std::string pass): username(un), password(pass), chatList(username) {}

Chat& Account::inviteToChat(const std::string friendName) {

    try {

        std::cout << "looking for existing chat with " + friendName << std::endl;
        return chatList.containedChat(friendName);

    } catch (not_found& e){

        std::cout << e.what() << std::endl;
        std::cout << "inviting " + friendName << std::endl;
        Chat newChat(username, friendName);
        chatList.addChat(newChat);
        return chatWith(friendName);
    }


}

void Account::removeChat(const std::string friendName) {

    try {

        chatList.deleteChat(friendName);

    } catch (not_found& e){

        std::cerr << e.what() << std::endl;
    }

}


Chat& Account::chatWith(const std::string friendName) {

    try {

        return chatList.containedChat(friendName);

    } catch (not_found& e) {

        std::cerr << e.what() << std::endl;
        throw e;

    }

}


std::string Account::shareContact() const {

    return username;

}

bool Account::checkCredentials(const std::string us, const std::string pass) const {

    if(us == username && pass == password)
        return true;
    else return false;

}

bool Account::operator==(const Account &right) const {

    if(username != right.username)
        return false;

    if(password != right.password)
        return false;

    if(chatList != right.chatList)
        return false;

    return true;
}