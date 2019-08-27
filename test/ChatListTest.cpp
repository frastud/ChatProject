//
// Created by Francesco on 2019-08-01.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../ChatList.h"



TEST(ChatList, ContainedChat){

    Chat aChat("Saverio", "Alice");
    Chat cChat("Saverio", "Cristian");

    ChatList chats("Saverio");

    ASSERT_THROW(chats.containedChat("someone"), not_found);

    chats.addChat(aChat);
    chats.addChat(cChat);

    ASSERT_EQ(aChat, chats.containedChat("Alice"));
    ASSERT_EQ(cChat, chats.containedChat("Cristian"));
    ASSERT_THROW(chats.containedChat("alice"), not_found);


}

TEST(ChatList, EqualityOperator){

    ChatList chats("Alice");
    Chat aChat("Alice", "Chiara");
    chats.addChat(aChat);

    ChatList equalChats("Alice");
    equalChats.addChat(aChat);
    ASSERT_TRUE(equalChats == chats);

    ChatList differentChats("Alice");
    differentChats.addChat(Chat("Alice", "Francesco"));
    ASSERT_FALSE(differentChats == chats);

    ChatList differentOwner("Martina");
    ASSERT_FALSE(differentOwner == chats);

}

TEST(ChatList, InequalityOperator){

    ChatList chats("Chiara");
    Chat cChat("Chiara", "Alice");
    chats.addChat(cChat);

    ChatList differentChats("Chiara");
    differentChats.addChat(Chat("Chiara", "Francesco"));
    ASSERT_TRUE(differentChats != chats);

    ChatList equalChats("Chiara");
    equalChats.addChat(cChat);
    ASSERT_FALSE(equalChats != chats);

    ChatList differentOwner("Marta");
    ASSERT_FALSE(differentOwner == chats);

}