//
// Created by Francesco on 2019-07-31.
//

#ifndef CHATPROJECT_CHAT_H
#define CHATPROJECT_CHAT_H

#include <string>
#include <vector>
#include "Message.h"

class Chat {
public:
    Chat(std::string mn, std::string on);

    std::string getMyName() const { return myName; };
    std::string getOtherName() const { return otherName; };

    void addMessage(const Message& newMessage);
    void readMessage(int i);
    int getNumUnreadMessage() const;
    bool validateSenderReceiver(const Message& message);

private:
    std::string myName, otherName;
    std::vector<Message> messages;
};


#endif //CHATPROJECT_CHAT_H
