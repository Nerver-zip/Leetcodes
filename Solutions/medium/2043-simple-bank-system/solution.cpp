using ll = long long;

class Bank {
public:
    Bank(vector<long long>& balance) {
        accounts = std::move(balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        --account1;
        --account2;

        if(account1 < 0 || account2 < 0 || account1 >= accounts.size() || account2 >= accounts.size())
            return false;

        ll& balance1 = accounts[account1];
        ll& balance2 = accounts[account2];

        if(balance1 < money)
            return false;

        balance1 -= money;
        balance2 += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        --account;
        if(account < 0 || account >= accounts.size())
            return false;
        
        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        --account;
        if(account < 0 || account >= accounts.size())
            return false;

        if(accounts[account] < money)
            return false;
        
        accounts[account] -= money;
        return true;
    }
private:
    vector<ll> accounts;
};