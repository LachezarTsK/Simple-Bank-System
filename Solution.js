
/**
 * @param {number[]} balance
 */
var Bank = function (balance) {
    this.balance = balance;
};

/** 
 * @param {number} fromAccount 
 * @param {number} toAccount 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function (fromAccount, toAccount, money) {
    if (!this.isValidAccount(fromAccount) || !this.isValidAccount(toAccount) || !this.accountHasResourcesForTransaction(fromAccount, money)) {
        return false;
    }
    this.balance[fromAccount - 1] -= money;
    this.balance[toAccount - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function (account, money) {
    if (!this.isValidAccount(account)) {
        return false;
    }
    this.balance[account - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function (account, money) {
    if (!this.isValidAccount(account) || !this.accountHasResourcesForTransaction(account, money)) {
        return false;
    }
    this.balance[account - 1] -= money;
    return true;
};

/** 
 * @param {number} account 
 * @return {boolean}
 */
Bank.prototype.isValidAccount = function (account) {
    return account > 0 && account <= this.balance.length;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.accountHasResourcesForTransaction = function (account, money) {
    return this.balance[account - 1] - money >= 0;
};
