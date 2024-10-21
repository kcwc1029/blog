
def make_icecream(*toppings):
    """這邊寫關於函數的說明
    Args:
        toppings (string): 各種配料
    Return:
        none
    """

    print("這個冰淇淋所加配料如下")
    for topping in toppings:
        print("--- ", topping)


def make_drink(size, drink):
    """這邊寫關於函數的說明
    Args:
        size (string): 
        drink (string): 各種飲料
    Return:
        none
    """
    print("所點飲料如下")
    print("--- ", size.title())
    print("--- ", drink.title())
