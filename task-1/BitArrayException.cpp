//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_1_BITARRAYEXCEPTION_CPP
#define TASK_1_BITARRAYEXCEPTION_CPP

#include <exception>
#include <string>

class BitArrayException : public std::exception {
private:
    std::string errorMessage;

public:
    BitArrayException(std::string errorMessage) {
        this->errorMessage = errorMessage;
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};


#endif //TASK_1_BITARRAYEXCEPTION_CPP
