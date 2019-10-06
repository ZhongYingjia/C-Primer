#ifndef Amount_H
#define Amount_H
#include <string>
class Account{
    public:
        void caculate(){
            amount += amount * interestRate;
        }
        static double rate(){
            return interestRate;
        }
        static void rate(double);
    private:
        std::string owner;
        static double interestRate;
        double amount;
        static constexpr double todayRate = 7.0;
        static double initRate(){ return todayRate; }
    
};

double Account::interestRate = initRate();
void Account::rate(double newRate){
    interestRate = newRate;

}

#endif