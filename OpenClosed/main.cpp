// This principle states that ¡°Software entities(classes, modules, functions, etc.) should be open for extension, 
// but closed for modification¡± which means you should be able to extend a class behavior, without modifying it.
// Let¡¯s understand Open / Closed Principle using an example :
// Imagine you have a class called PaymentProcessor that processes payments for an online store.
// Initially, the PaymentProcessor class only supports processing payments using credit cards.
// However, you want to extend its functionality to also support processing payments using PayPal.
// Instead of modifying the existing PaymentProcessor class to add PayPal support, 
// you can create a new class called PayPalPaymentProcessor that extends the PaymentProcessor class.
// This way, the PaymentProcessor class remains closed for modification but open for extension, 
// adhering to the Open - Closed Principle.Let¡¯s understand this through the code implementation.

#include <iostream>
#include <string>

// Base class for payment processing
class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

// Credit card payment processor
class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};

// PayPal payment processor
class PayPalPaymentProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

void processPayment(PaymentProcessor* processor, double amount) {
    processor->processPayment(amount);
}

int main() {
    CreditCardPaymentProcessor creditCardProcessor;
    PayPalPaymentProcessor payPalProcessor;

    processPayment(&creditCardProcessor, 100.00); // Processing credit card payment
    processPayment(&payPalProcessor, 150.00);     // Processing PayPal payment

    return 0;
}