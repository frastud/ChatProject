//
// Created by Francesco on 2019-07-31.
//

#include "gtest/gtest.h"
#include "../Message.h"
#include "../Chat.h"

TEST(Chat, Constructor){

    Chat messenger("Alice", "Ludovica");

    ASSERT_EQ("Alice", messenger.getMyName());
    ASSERT_EQ("Ludovica", messenger.getOtherName());

}


TEST(Chat, ValidateSenderReceiver){

    Chat messenger("Marco", "Sara");
    Message mMessage("Marco", "Sara", "nice party yesterday!");
    Message sMessage("Sara", "Marco", "I'm glad you enjoyed it");
    Message uMessage("Unknown", "Sara", "thank you for yesterday");


    ASSERT_EQ(true, messenger.validateSenderReceiver(mMessage));
    ASSERT_EQ(true, messenger.validateSenderReceiver(sMessage));
    ASSERT_EQ(false, messenger.validateSenderReceiver(uMessage));


}


TEST(Chat, UnreadMessage){

    Chat messenger("Alice", "Ludovica");
    Message aMessage("Alice", "Ludovica", "do you want to go out this night", true);
    messenger.addMessage(aMessage);

    ASSERT_EQ(0, messenger.getNumUnreadMessage());

    Message lMessage("Ludovica", "Alice", "sure");
    messenger.addMessage(lMessage);

    ASSERT_EQ(1, messenger.getNumUnreadMessage());

}

TEST(Chat, readMessage){

    Chat messenger("Martina", "Cristian");
    Message cMessage("Cristian", "Martina", "how are you?");
    messenger.addMessage(cMessage);
    Message cMessage1("Cristian", "Martina", "...so?");
    messenger.addMessage(cMessage1);
    Message mMessage("Martina", "Cristian", "fine, and you?", true);
    messenger.addMessage(mMessage);

    ASSERT_NO_THROW(messenger.readMessage(0));
    ASSERT_NO_THROW(messenger.readMessage(1));
    ASSERT_NO_THROW(messenger.readMessage(2));
    ASSERT_THROW(messenger.readMessage(-1), std::out_of_range);
    ASSERT_THROW(messenger.readMessage(3), std::out_of_range);

    cMessage.setRead(false);
    cMessage1.setRead(false);

    messenger.readMessage(0);
    messenger.readMessage(1);

    ASSERT_EQ(0, messenger.getNumUnreadMessage());

}







