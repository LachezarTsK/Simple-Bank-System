
#include <iterator>
#include <vector>
using namespace std;

class Bank {
    /*
     In C++, declaring: 'vector<long long> balance' and then 'this->balance = balance' copies unnecessarily the whole vector.
     Doing the above in Java and JavaScript is fine: there are no copies, just a reference from the instance variable.
     */
    vector<long long>::iterator iterator_balance;
    size_t size;

public:
    Bank(vector<long long>& balance) {
        size = balance.size();
        iterator_balance = balance.begin();
    }

    bool transfer(int fromAccount, int toAccount, long long money) {
        if (!isValidAccount(fromAccount) || !isValidAccount(toAccount) || !accountHasResourcesForTransaction(fromAccount, money)) {
            return false;
        }
        iterator_balance[fromAccount - 1] -= money;
        iterator_balance[toAccount - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) {
            return false;
        }
        iterator_balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValidAccount(account) || !accountHasResourcesForTransaction(account, money)) {
            return false;
        }
        iterator_balance[account - 1] -= money;
        return true;
    }

private:
    bool isValidAccount(int account) {
        return account > 0 && account <= size;
    }

    bool accountHasResourcesForTransaction(int account, long money) {
        return iterator_balance[account - 1] - money >= 0;
    }
};
