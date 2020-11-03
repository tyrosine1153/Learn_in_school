import re
import requests

pattern = re.compile(r'[a-z][A-Z]{3}([a-z])[A-Z]{3}[a-z]')
URL = 'http://www.pythonchallenge.com/pc/def/equality.html'
response = requests.get(URL)
cryptogram = response.text[response.text.find('<!--'):]

temp = re.findall(pattern, cryptogram)  # findall 함수가 그룹만 따로 추출함
new_string = ''.join(temp)
print(new_string)
print(''.join(re.findall(pattern, cryptogram)))
# (?P<그룹명>정규식), sub(,), \w: [a-zA-Z0-9_], \s: 공백문자, \d: 숫자
# match search findall
# print(''.join(re.findall(re.compile(r'[a-z][A-Z]{3}([a-z])[A-Z]{3}[a-z]'), requests.get('http://www.pythonchallenge.com/pc/def/equality.html').text[(requests.get('http://www.pythonchallenge.com/pc/def/equality.html').text.find('<!--')):])))
# Python_challenge_3
