//
// Created by Francesco on 2019-08-27.
//

#include "gtest/gtest.h"
#include "../not_found.h"


TEST(not_found, what) {

    not_found error("chat", "friendName");
    std::string errorMessage(error.what()); // const char* converted into string
    ASSERT_EQ("there is no chat named: friendName", errorMessage);

}