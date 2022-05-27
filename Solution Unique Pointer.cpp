
#include <memory>
#include <vector>
using namespace std;

class Bank {
    /*
     In C++, declaring: 'vector<long long> balance' and then 'this->balance = balance' copies unnecessarily the whole vector.
     Doing the above in Java and JavaScript is fine: there are no copies, just a reference from the instance variable.
     */
    unique_ptr<vector<long long>> pointer_balance; //raw pointers should be a thing of the past.

public:
    Bank(vector<long long>& balance) {
        pointer_balance = make_unique<vector<long long>>(balance);
    }

    bool transfer(int fromAccount, int toAccount, long long money) {
        if (!isValidAccount(fromAccount) || !isValidAccount(toAccount) || !accountHasResourcesForTransaction(fromAccount, money)) {
            return false;
        }
        pointer_balance->at(fromAccount - 1) -= money;
        pointer_balance->at(toAccount - 1) += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) {
            return false;
        }
        pointer_balance->at(account - 1) += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValidAccount(account) || !accountHasResourcesForTransaction(account, money)) {
            return false;
        }
        pointer_balance->at(account - 1) -= money;
        return true;
    }

private:
    bool isValidAccount(int account) {
        return account > 0 && account <= pointer_balance->size();
    }
    
    bool accountHasResourcesForTransaction(int account, long money) {
        return pointer_balance->at(account - 1) - money >= 0;
    }
};
