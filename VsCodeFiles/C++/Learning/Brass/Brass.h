#include <string>
class Brass{
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    double Balance() const;
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass();
};

class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesbank; 
public:
    BrassPlus(const std::string & s ="Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    void ReseMax(double m) { maxLoan = m; }
    void ReseRate(double r) { rate = r; };
    void ResetOwes() { owesbank = 0; }
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
};
