//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_1_BITARRAYEXCEPTION_CPP
#define TASK_1_BITARRAYEXCEPTION_CPP

#include <exception>
#include <string>

class BitArrayException : public std::exception {
private:
    std::string error_message;

public:
    BitArrayException(std::string error_message) {
        this->error_message = error_message;
    }

    const char* what() const noexcept override {
        return error_message.c_str();
    }
};


#endif //TASK_1_BITARRAYEXCEPTION_CPP
