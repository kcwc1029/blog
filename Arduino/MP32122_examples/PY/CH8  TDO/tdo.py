import time

def tdo(sec):
    while sec:
        m=sec//60
        s=sec%60
        sec_format = '{:02d}:{:02d} '.format(m, s)
        print(sec_format)
        time.sleep(1)
        sec -= 1        
    print('Time out')
tdo(80)
