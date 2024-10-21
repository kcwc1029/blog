class Banks():
    def __init__(self, name):    
        self.__name = name
        self.__balance = 0
        self.__title = "Bank"

    def save_money(self, money): # 設計存款方法
        self.__balance += money
        print("存款 ", money, " 完成")

    def withdraw_money(self, money): # 設計提款方法
        self.__balance -= money             
        print("提款 ", money, " 完成")

    def get_balance(self):   # 獲得存款餘額
        print(self.__name.title(), " 目前餘額: ", self.__balance)

    def bank_title(self):  # 獲得銀行名稱
        return self.__title


class Tainan_bank(Banks):
    def __init__(self, name):
        self.__title = "Tainan bank"
    def bank_title(self):  # 獲得銀行名稱
        return self.__title
