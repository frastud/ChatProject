//
// Created by Francesco on 2019-07-30.
//

#include "gtest/gtest.h"
#include "../Message.h"


TEST(Message, Constructor){

    Message defaultReadMessage("Beatrice", "Arturo", "ho caricato la versione 1.6");

    ASSERT_EQ("Beatrice", defaultReadMessage.getSender());
    ASSERT_EQ("Arturo", defaultReadMessage.getReceiver());
    ASSERT_EQ("ho caricato la versione 1.6", defaultReadMessage.getText());
    ASSERT_EQ(false, defaultReadMessage.isRead());

    Message specificReadMessage("Arturo", "Beatrice", "dovrò fare il merge", true);

    ASSERT_EQ("Arturo", specificReadMessage.getSender());
    ASSERT_EQ("Beatrice", specificReadMessage.getReceiver());
    ASSERT_EQ("dovrò fare il merge", specificReadMessage.getText());
    ASSERT_EQ(true, specificReadMessage.isRead());
}

TEST(Message, SettingRead){

    Message m("unknown", "Marco", "ho sbagliato numero", false);
    ASSERT_EQ(false, m.isRead());

    m.setRead(true);
    ASSERT_EQ(true, m.isRead());

}