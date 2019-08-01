//
// Created by Francesco on 2019-07-30.
//

#include "Message.h"
using namespace std;

Message::Message(std::string sen, std::string rec, std::string tex, bool rea): sender(move(sen)), receiver(move(rec)), text(move(tex)),
                   read(rea) {}

bool Message::operator==(const Message &right) const {

    if(right.sender != sender)
        return false;

    if(right.receiver != receiver)
        return false;

    if(right.text != text)
        return false;

    if(right.read != read)
        return false;

    return true;

}