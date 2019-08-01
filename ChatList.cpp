//
// Created by Francesco on 2019-08-01.
//

#include "ChatList.h"



void ChatList::addChat(const Chat &chat) {

    chats.emplace(chat.getOtherName(),chat);

}

void ChatList::deleteChat(const std::string &chatName) {

    if(!chats.empty()){

        std::map<std::string, Chat>::iterator chat=chats.find(chatName);

        if(chat != chats.end())
            chats.erase(chat);

    }
}

Chat ChatList::findChat(const std::string &chatName) {

    if(!chats.empty()) {

        std::map<std::string, Chat>::iterator chat = chats.find(chatName);

        if(chat != chats.end())
            return chat->second;

    }

}

int ChatList::getNumChat() const {

    return chats.size();

}