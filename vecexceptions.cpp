#include "vecexceptions.h"

notA3DVectorException::notA3DVectorException(std::string reason) :
    message("Vector are invalid for performing the operation: " + reason)
{ }

char const * notA3DVectorException::what()
{ return message.c_str(); }

sizesAreNotEqualException::sizesAreNotEqualException(std::string reason) :
    message("Sizes aren't  equal for perfoming the operation: " + reason)
{ }

char const * sizesAreNotEqualException::what()
{ return message.c_str(); }
