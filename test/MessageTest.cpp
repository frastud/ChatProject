//
// Created by Francesco on 2019-07-30.
//

#include "gtest/gtest.h"
#include "../Message.h"


TEST(Message, Constructor){

    Message defaultReadMessage("Beatrice", "Arturo", "I have uploaded version 1.6");

    ASSERT_EQ("Beatrice", defaultReadMessage.getSender());
    ASSERT_EQ("Arturo", defaultReadMessage.getReceiver());
    ASSERT_EQ("I have uploaded version 1.6", defaultReadMessage.getText());
    ASSERT_EQ(false, defaultReadMessage.isRead());

    Message specificReadMessage("Arturo", "Beatrice", "i'll have to do merge", true);

    ASSERT_EQ("Arturo", specificReadMessage.getSender());
    ASSERT_EQ("Beatrice", specificReadMessage.getReceiver());
    ASSERT_EQ("i'll have to do merge", specificReadMessage.getText());
    ASSERT_EQ(true, specificReadMessage.isRead());
}

TEST(Message, SettingRead){

    Message m("unknown", "Marco", "i dialed the wrong number", false);
    ASSERT_EQ(false, m.isRead());

    m.setRead(true);
    ASSERT_EQ(true, m.isRead());

}