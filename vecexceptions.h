#pragma once

#include <exception>
#include <string>

class notA3DVectorException : public std::exception
{
    std::string message;
public:
    notA3DVectorException(std::string);
    virtual char const* what();
};

class sizesAreNotEqualException : public std::exception
{
    std::string message;
public:
    sizesAreNotEqualException(std::string);
    virtual char const* what();
};
