#!/usr/bin/python3
'''UTF-8 Validation module'''


def validUTF8(data):
    '''determines if a given data set represents a valid UTF-8 encoding
    Args:
        data is the data to be checked
    Return: True if data is a valid UTF-8 encoding, else return False
    Important: A character in UTF-8 can be 1 to 4 bytes long
               The data set can contain multiple characters
               The data will be represented by a list of integers
               Each integer represents 1 byte of data
    '''
    if not data:
        return False

    slots = 0
    for n in data:
        if type(n) is not int:
            return False
        str_bin = bin(n)  # binary str representation of n
        if len(str_bin) >= 10:  # str has a "0b" at the begining
            str_bin = str_bin[-8:]
        else:
            str_bin = '0' + str_bin[2:]  # 8 bits complete
        if slots == 0:  # checks the amount of bytes encoded
            for b in str_bin:
                if b == '0' and slots == 0:
                    break
                elif b == '1':
                    slots += 1
                else:
                    break
            if slots == 1 or slots > 4:
                return False
            elif slots > 1:
                slots -= 1
        elif slots > 0:  # check if is a deppendent slot
            if str_bin[:2] != '10':  # checks for a continuation header
                return False
            else:
                slots -= 1
    if slots > 0:
        return False

    return True
