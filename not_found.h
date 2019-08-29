//
// Created by Francesco on 2019-08-27.
//

#ifndef CHATPROJECT_NOT_FOUND_H
#define CHATPROJECT_NOT_FOUND_H

#include <exception>
#include <string>

class not_found: public std::exception {

public:

     not_found(const std::string thing, const std::string name) {

        std::string error="there is no " + thing + " named: " + name;
        occurredError=error.c_str();

    };

    virtual const char* what() const throw()

    {
        return occurredError;
    }

private:

    const char* occurredError;

};


#endif //CHATPROJECT_NOT_FOUND_H
