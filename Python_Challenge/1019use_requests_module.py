import requests

URL = 'http://www.pythonchallenge.com/pc/def/ocr.html'
response = requests.get(URL)
cryptogram = response.text[response.text.find('%%'):]
new_string = ''
for c in cryptogram:
    if c.isalpha():
        new_string += c
print(new_string)


"""
isalnum()
isalpha()
isdigit()
주석 부분만 찾아 문자열 자르기
알파벳을 찾아 새로운 리스트에 넣기
"""
# Python_challenge_2
