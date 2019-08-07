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

Chat& ChatList::containedChat(const std::string &chatName) {

    if(!chats.empty()) {

        std::map<std::string, Chat>::iterator chat = chats.find(chatName);

        if(chat != chats.end())
            return chat->second;

    }

}


bool ChatList::findChat(const std::string &chatName) const {

    if(!chats.empty()) {

        auto chat = chats.find(chatName);

        if(chat != chats.end())
            return true;
        else return false;

    }

    return false;
}


bool ChatList::operator==(const ChatList &right) const {

    if(chats != right.chats)
        return false;

    return true;
}

bool ChatList::operator!=(const ChatList &right) const {

    if(*this == right)
        return false;

    return true;

}