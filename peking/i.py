


from sys import *
from math import log10

"""
                :                0   :    0
   0.5 - 4.5    :            1 - 9   :    1 - 9
   5   - 9      :           10 - 18  :   11 - 99
   9.5 - 54     :           19 - 108 :  101 - 999
  54.5 - 99     :          109 - 198 : 1001 - 9999

"""

# stdout.write()
# stdin.readlines()

def digits(n):
    return int(log10(n)) + 1

def func(k, is_middle=False):
    k = str(k)
    if len(k) > 2:
        if k[0:2] == '10':
            if all([ x == '9' for x in k[2:]]):
                n = (len(k) - 2) * 2 + 1
            else: # smaller than 10999... but larger than 10000...
                n = (len(k) - 2) * 2 + 1
        else: #
            if k[0] == '1':
                if all([x == '9' for x in k[1:]]):
                    n = (len(k) - 1) * 2 + 1
                else: # smaller than 1999... but larger than 109...
                    n = (len(k) - 1) * 2
            else:
                n = (len(k) - 1) * 2 + 1
        
        # print("n:", n)
        if n % 2 == 0:
            leading = int(int(k[0:2]) - 20) % 10
        else:
            leading = int(int(k[0:2]) - 1)
        
        return "{0}{1}{0}".format(leading, func(int(k[1:])+1, True))
    elif len(k) == 1:
        return str(int(k)-1)
    elif len(k) == 2: # 10 is 9, 11 is 11, 20 is 101
        if k == '10':
            return '9'
        elif int(k) < 20:
            return str((int(k) - 10) * 11)
        else:
            return "{0}{1}{0}".format(int(int(k)/10 - 1), int((int(k) - 20) % 10))
    else: # len == 0
        print("FATAL")
        return ""



# line = stdin.readline()
n = 300 # int(line)
for i in range(n):
    # print("length: ", len(k)) # '\n' is probably included
    n = 0 # n is reusable because range(n) is generated
    # k = stdin.readline()[:-1]
    # print(func(k-1))
    print("{}: {}".format(i, func(i+1)))
    