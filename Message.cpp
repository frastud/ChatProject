//
// Created by Francesco on 2019-07-30.
//

#include "Message.h"
using namespace std;

Message::Message(std::string sen, std::string rec, std::string tex, bool rea): sender(move(sen)), receiver(move(rec)), text(move(tex)),
                   read(rea) {}