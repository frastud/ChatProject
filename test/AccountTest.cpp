//
// Created by Francesco on 2019-08-02.
//

#include "gtest/gtest.h"
#include "../Account.h"

TEST(Account, ShareContact){

    Account sol("6151930", "******");
    ASSERT_EQ("6151930", sol.shareContact());
    ASSERT_NE("6151920", sol.shareContact());

}

TEST(Account, CheckCredentials){

    Account ebay("POmidyar67", "founder_67_e2001");
    ASSERT_TRUE(ebay.checkCredentials("POmidyar67", "founder_67_e2001"));
    ASSERT_FALSE(ebay.checkCredentials("POmidyar67", "founder"));
    ASSERT_FALSE(ebay.checkCredentials("POmidyar", "founder_67_e2001"));

}

TEST(Account, InviteToChat){

    Account messenger("ludo_stud97", "********");
    const std::string friendName="Alice97";
    const std::string noFriend="Andre_95";
    Chat aChat("ludo_stud97", friendName);
    Chat nChat("ludo_stud97", noFriend);


    ASSERT_EQ(aChat, messenger.inviteToChat(friendName));
    ASSERT_EQ(nChat, messenger.inviteToChat(noFriend));
    ASSERT_NE(aChat, messenger.inviteToChat(noFriend));

}

TEST(Account, ChatWith){

    Account snapchat("me", "********");
    const std::string friendName="Alfred";

    snapchat.inviteToChat(friendName);
    Chat myFriend("me", friendName);
    Chat hisChat(friendName, "me");


    ASSERT_EQ(myFriend, snapchat.chatWith(friendName));
    ASSERT_NE(hisChat, snapchat.chatWith(friendName));
    ASSERT_THROW(snapchat.chatWith("someone"), not_found);

}

TEST(Account, EqualityOperator){

    Account account("Shady97", "shadyPassword");
    account.inviteToChat("Simon");

    Account equalAccount("Shady97", "shadyPassword");
    equalAccount.inviteToChat("Simon");
    ASSERT_TRUE(equalAccount == account);

    Account userNameAccount("Anna97", "shadyPassword");
    userNameAccount.inviteToChat("Simon");
    ASSERT_FALSE(userNameAccount == account);

    Account passwordAccount("Shady97", "******");
    passwordAccount.inviteToChat("Simon");
    ASSERT_FALSE(passwordAccount == account);

    Account chatListAccount("Shady97", "shadyPassword");
    chatListAccount.inviteToChat("Vittoria");
    ASSERT_FALSE(chatListAccount == account);

}