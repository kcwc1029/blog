fp = open("note.txt", "w")
if fp != None:
    print("檔案開啟成功!")
    fp.write("陳會安\n")
    fp.write("江小魚\n")
    print("已經寫入2個姓名到檔案note.txt!")
fp.close()