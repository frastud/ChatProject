//
// Created by Francesco on 2019-08-01.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../ChatList.h"



TEST(ChatList, ContainedChat){

    Chat aChat("me", "Alice");
    Chat cChat("Alice", "Cristian");

    ChatList chats;
    chats.addChat(aChat);
    chats.addChat(cChat);

    ASSERT_EQ(aChat, chats.containedChat("Alice"));
    ASSERT_EQ(cChat, chats.containedChat("Cristian"));

}

TEST(ChatList, FindChat){

    Chat cChat("Martina", "Corinna");
    Chat lChat("Alessandro", "Ludovica");

    ChatList chats;
    chats.addChat(cChat);
    chats.addChat(lChat);

    ASSERT_TRUE(chats.findChat("Corinna"));
    ASSERT_TRUE(chats.findChat("Ludovica"));
    ASSERT_FALSE(chats.findChat("Alice"));

}