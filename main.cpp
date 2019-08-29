#include <iostream>
#include "User.h"

int main() {

    User user("Cristian", "Mencarelli");

    const std::string userName="Cri_Menca93";
    const std::string password="*********";

    if(user.createAccount(userName, password))
        std::cout << "Welcome, you're in! Your username is: " << userName << std::endl;

    else std::cout << "you already have an account!" << std::endl;

    try {

        Account &userAccount = user.logIn(userName, password);
        Chat& chat=userAccount.inviteToChat("Alice97");
        Message helloMessage(userAccount.shareContact(), "Alice97", "Hi, I'm the guy from last night", true);
        chat.addMessage(helloMessage);
        Message declineMessage("Alice97", userName, "I don't remember, I was drunk");
        chat.addMessage(declineMessage);
        chat.readMessage(1);
        user.deleteAccount(userName, password);

        const std::string newName= "CM_93";

        if(user.createAccount(newName, password))
            std::cout << "Welcome, you're in! Your username is: " << newName << std::endl;

    }catch (not_found& e){
        std::cerr << e.what() << std::endl;
        std::cout << "wrong credentials!" << std::endl;
    }

    // after a while

    if(user.createAccount(password))
        std::cout << "Welcome, you're in! Your username is: CM.CristianMencarelli" << std::endl;

    else std::cout << "you already have an account!" << std::endl;

    return 0;
}