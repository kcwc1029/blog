#include <iostream>
#include <string>
#include <conio.h>  // 引入 _getch() 函數使用

using namespace std;

class ATM {
private:
    string account_no;  // 帳號 
    string name;        // 使用者姓名 
    string PIN;         // 使用者的帳戶 PIN 碼 (無法更改)
    double balance;     // 使用者帳戶餘額 
    string mobile_no;   // 使用者的手機號碼 

public:
    // 初始化設定使用者資料
    void setData(string account_No_a, string name_a, string PIN_a, double balance_a, string mobile_No_a) {
        account_no = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_No_a;
    }

    // 取得帳號資料
    string getAccountNo() { return account_no; }

    // 取得姓名
    string getName() { return name; }

    // 取得PIN
    string getPIN() { return PIN; }

    // 取得電話號碼
    string getMobileNo() { return mobile_no; }

    // 取得存款餘額
    double getBalance() { return balance; }

    // 修改手機號碼 (驗證舊手機號碼)
    void setMobile(string old_mobile_no, string new_mobile_no) {
        if (old_mobile_no == mobile_no) {
            mobile_no = new_mobile_no; // 更新手機號碼
            cout << "Successfully Updated Mobile No.\n";
        } else {
            cout << "Incorrect! Old Mobile No.\n";
        }
        _getch();  // 等待用戶按下任意鍵繼續（不顯示按下的字符）
    }

    // 提款功能
    void cashWithDraw(int money) {
        if (money > 0 && money <= balance) {
            balance -= money; // 扣除提款金額
            cout << "Please Collect Your Cash\n";
            cout << "Available Balance: " << balance << "\n";
        } else {
            cout << "Invalid Input or Insufficient Balance\n";
        }
        _getch();  // 等待用戶按下任意鍵繼續（不顯示按下的字符）
    }
};

//////////////////////////////////////////////////////////////////////////////////
// 主程式入口
int main() {
    int order = 0; 
    string enterAccountNo;
    string enterPIN;

    ATM user1;
    user1.setData("001", "TA1", "1111", 45000.90, "0978123123");

    while (true) {
        system("cls");  // 清空螢幕
        cout << "\n**** Welcome to ATM *****\n";
        cout << "Enter Your Account No: ";
        cin >> enterAccountNo;
        cout << "Enter PIN: ";
        cin >> enterPIN;

        if (enterAccountNo == user1.getAccountNo() && enterPIN == user1.getPIN()) {
            while (true) {
                int money = 0;
                string oldMobileNo, newMobileNo;

                system("cls");  // 清空螢幕

                // User Interface
                cout << "\n**** Welcome to ATM *****\n";
                cout << "Select Options\n";
                cout << "1. Check Balance\n";
                cout << "2. Cash Withdraw\n";
                cout << "3. Show User Details\n";
                cout << "4. Update Mobile No.\n";
                cout << "5. Exit\n";
                cout << "Enter Option: ";
                cin >> order;

                switch (order) {
                    case 1:
                        cout << "Your Bank Balance is: " << user1.getBalance() << "\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                    case 2:
                        cout << "Enter the Amount: ";
                        cin >> money;
                        user1.cashWithDraw(money);
                        break;
                    case 3:
                        cout << "*** User Details ***\n";
                        cout << "Account No: " << user1.getAccountNo() << "\n";
                        cout << "Name: " << user1.getName() << "\n";
                        cout << "Balance: $" << user1.getBalance() << "\n";
                        cout << "Mobile No: " << user1.getMobileNo() << "\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                    case 4:
                        cout << "Enter Old Mobile No: ";
                        cin >> oldMobileNo;
                        cout << "Enter New Mobile No: ";
                        cin >> newMobileNo;
                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;
                    case 5:
                        exit(0);  // 結束程式
                    default:
                        cout << "Enter Valid Option!\n";
                        _getch();  // 等待用戶按下任意鍵繼續
                        break;
                }
            }
        } else {
            cout << "Invalid Account No or PIN. Please Try Again.\n";
            _getch();  // 等待用戶按下任意鍵繼續
        }
    }
    return 0;
}
