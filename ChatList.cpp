//
// Created by Francesco on 2019-08-01.
//

#include "ChatList.h"


ChatList::ChatList(const std::string owner): chatOwner(owner) {}

void ChatList::addChat(const Chat &chat) {

    if(chat.getMyName() == chatOwner) {
        chats.emplace(chat.getOtherName(), chat);
    }

}

void ChatList::deleteChat(const std::string &chatName) {

    if(!chats.empty()){

        std::map<std::string, Chat>::iterator chat=chats.find(chatName);

        if(chat != chats.end())
            chats.erase(chat);
        else throw not_found("chat", chatName);

    }

    throw  not_found("chat", chatName);

}

Chat& ChatList::containedChat(const std::string &chatName) {

    if(!chats.empty()) {

        std::map<std::string, Chat>::iterator chat = chats.find(chatName);

        if(chat != chats.end())
            return chat->second;

        else throw not_found("chat", chatName);

    }

    throw not_found("chat", chatName);

}


bool ChatList::operator==(const ChatList &right) const {

    if(chatOwner != right.chatOwner)
        return false;

    if(chats != right.chats)
        return false;

    return true;
}

bool ChatList::operator!=(const ChatList &right) const {

    if(*this == right)
        return false;

    return true;

}