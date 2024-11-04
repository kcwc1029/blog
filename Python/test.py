from multiprocessing import Process, Value, Array, Lock
from time import sleep

# 定義第一個任務
def task1(lock, n, a):
    lock.acquire()  # 獲取鎖
    num1 = n.value
    num1 += 100
    sleep(0.2)
    n.value = num1

    for i in range(len(a)):
        a[i] = a[i] * a[i]
    lock.release()  # 釋放鎖

# 定義第二個任務
def task2(lock, n, a):
    lock.acquire()  # 獲取鎖
    num2 = n.value
    num2 += 200
    sleep(0.2)
    n.value = num2

    for i in range(len(a)):
        a[i] = -a[i]
    lock.release()  # 釋放鎖

if __name__ == '__main__':
    lock = Lock()
    num = Value('d', 0.0)  # 定義共享變數，double 類型
    arr = Array('i', range(10))  # 定義共享陣列，int 類型

    # 創建進程
    p1 = Process(target=task1, args=(lock, num, arr))
    p2 = Process(target=task2, args=(lock, num, arr))

    # 啟動進程
    p1.start()
    p2.start()

    # 等待進程結束
    p1.join()
    p2.join()

    # 輸出結果
    print(f"num = {num.value}")
    print(f"arr = {arr[:]}")
