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

TEST(Chat, EqualityOperator) {

    Chat chat("Giacomo", "Corinna");
    Message message("Giacomo", "Corinna", "Hello!");
    chat.addMessage(message);

    Chat trueChat("Giacomo", "Corinna");
    trueChat.addMessage(message);
    ASSERT_TRUE(trueChat == chat);

    Chat myNameChat("Alberto", "Corinna");
    myNameChat.addMessage(message);
    ASSERT_FALSE(myNameChat == chat);

    Chat otherNameChat("Giacomo", "Federico");
    otherNameChat.addMessage(message);
    ASSERT_FALSE(otherNameChat == chat);

    Chat messageChat("Giacomo", "Corinna");
    messageChat.addMessage(Message("Giacomo", "Corinna", "See you then"));
    ASSERT_FALSE(messageChat == chat);

}

TEST(Chat, InequalityOperator){

    Chat chat("Corinna", "Giacomo");
    Message message("Corinna", "Giacomo", "Hi!");
    chat.addMessage(message);

    Chat equalChat("Corinna", "Giacomo");
    equalChat.addMessage(message);
    ASSERT_FALSE(equalChat != chat);

    Chat myNameChat("Alberto", "Giacomo");
    myNameChat.addMessage(message);
    ASSERT_TRUE(myNameChat != chat);

    Chat otherNameChat("Corinna", "Federico");
    otherNameChat.addMessage(message);
    ASSERT_TRUE(otherNameChat != chat);

    Chat messageChat("Corinna", "Giacomo");
    messageChat.addMessage(Message("Corinna", "Giacomo", "I have not seen you for a long time"));
    ASSERT_TRUE(messageChat != chat);

}




