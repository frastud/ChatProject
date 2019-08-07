//
// Created by Francesco on 2019-08-01.
//

#ifndef CHATPROJECT_CHATLIST_H
#define CHATPROJECT_CHATLIST_H

#include <map>
#include <string>
#include "Chat.h"

class ChatList {
public:

    ChatList(){};

    void addChat(const Chat& chat);
    void deleteChat(const std::string  &chatName);
    Chat& containedChat(const std::string &chatName);
    bool findChat(const std::string &chatName) const;
    bool operator == (const ChatList& right) const;
    bool operator != (const ChatList& right) const;

private:
    std::map<std::string, Chat> chats;

};


#endif //CHATPROJECT_CHATLIST_H
