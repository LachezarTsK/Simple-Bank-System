
public class Bank {

    long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    public boolean transfer(int fromAccount, int toAccount, long money) {
        if (!isValidAccount(fromAccount) || !isValidAccount(toAccount) || !accountHasResourcesForTransaction(fromAccount, money)) {
            return false;
        }
        balance[fromAccount - 1] -= money;
        balance[toAccount - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (!isValidAccount(account)) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (!isValidAccount(account) || !accountHasResourcesForTransaction(account, money)) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }

    private boolean isValidAccount(int account) {
        return account > 0 && account <= balance.length;
    }

    private boolean accountHasResourcesForTransaction(int account, long money) {
        return balance[account - 1] - money >= 0;
    }
}
