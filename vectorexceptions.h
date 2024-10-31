#ifndef VECTOREXCEPTIONS_H
#define VECTOREXCEPTIONS_H

#include <cstdio>
#include <exception>

class different_sizes : public std::exception {
    char * final_message;

public:
    different_sizes(char* message)
    {
        sprintf(final_message, "vectors have different size: %s", message);
    }

    char* what()
    {
        return final_message;
    }
};

#endif // VECTOREXCEPTIONS_H
