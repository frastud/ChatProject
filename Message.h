//
// Created by Francesco on 2019-07-30.
//

#ifndef CHATPROJECT_MESSAGE_H
#define CHATPROJECT_MESSAGE_H

#include <string>

class Message {
public:
    Message(std::string sen, std::string rec, std::string tex, bool rea=false);

    std::string getSender() const { return sender; }
    std::string getReceiver() const { return receiver; }
    std::string getText() const { return text; }

    bool isRead() const { return read; }
    void setRead(bool r) { read=r; }

private:
    std::string sender, receiver, text;
    bool read;

};


#endif //CHATPROJECT_MESSAGE_H
