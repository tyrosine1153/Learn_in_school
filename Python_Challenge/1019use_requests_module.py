import requests


def func():
    URL = 'http://www.pythonchallenge.com/pc/def/ocr.html'
    response = requests.get(URL)
    cryptogram = response.text[response.text.find('%%'):]
    new_string = ''
    for c in cryptogram:
        if c.isalpha():
            new_string += c
    return new_string


def func2():
    URL = 'http://www.pythonchallenge.com/pc/def/equality.html'
    response = requests.get(URL)
    cryptogram = response.text[response.text.find('<!--'):]
    new_string = ''
    for c in cryptogram:
        if True:
            new_string += c
    return new_string


mode = input("1. 2번\t2. 3번\n: ")
if mode == '1':
    print(func())
elif mode == '2':
    print(func2())


"""
isalnum()
isalpha()
isnum()
주석 부분만 찾아 문자열 자르기
알파벳을 찾아 새로운 리스트에 넣기
"""
