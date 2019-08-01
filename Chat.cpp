//
// Created by Francesco on 2019-07-31.
//

#include "Chat.h"
#include <iostream>

using namespace std;

Chat::Chat(std::string mn, std::string on): myName(move(mn)), otherName(move(on)) {}

bool Chat::validateSenderReceiver(const Message &message) {

    if(message.getSender() == myName && message.getReceiver() == otherName)
        return true;

    if(message.getSender() == otherName && message.getReceiver() == myName)
        return true;

    return false;
}

void Chat::addMessage(const Message &newMessage) {

    if(validateSenderReceiver(newMessage)) {
        messages.push_back(newMessage);
    }

}

void Chat::readMessage(int i) {

    if(i >= 0 && i < messages.size()){

        Message& message=messages[i];

        if(message.getReceiver() == myName){
            std::cout << "sender: " << message.getSender() << std::endl;
            std::cout << "text  : " << message.getText() << std::endl;
            message.setRead(true);
        } else std::cout << "you wrote this message! " << std::endl;

    } else throw std::out_of_range("bad index");

}

int Chat::getNumUnreadMessage() const {

    int unreadMessage=0;

    for (auto & message : messages){

        if(!message.isRead())
            unreadMessage+=1;

    }

    return unreadMessage;
}

bool Chat::operator==(const Chat &right) const {

    if(right.myName != myName || right.otherName != otherName)
        return false;

    if(right.messages != messages)
        return false;

    return true;

}