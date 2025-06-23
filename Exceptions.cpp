// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class CustomException : public std::exception {
public:
    explicit CustomException(const std::string& message) msg_(message) {}

    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;

};


bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic()) {
            std::cout << "even more custom application logic successful." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught in do_custom_application_logic: " << e.what() << std::endl;

    }
}
    

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0.0f) {
        throw std::overflow_error("Divide by zero in divide()");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::overflow_error& e) {
        std::cerr << "Overflow error caught in do_division: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();

    }
    catch (const CustomException& ce) {
        std::cerr << "Custom exception caught in main: " << ce.what() << std::endl;
    }

    catch (const std::exception& se) {
        std::cerr << "Standard exception caught in main: " se.what() << std::endl;
    }

    catch (...) {
        std::cerr << "Unkown exception caught in main: " << std::endl;
    }

    std::cout << "Program continues after exception handling." << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu