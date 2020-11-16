import urllib
import requests
import re
pattern = re.compile(r'[0-9]+')
url = 'http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=12345'

while True:
    temp = requests.get(url).text
    try:
        number = re.findall(pattern, temp)
        print(url)
        if len(number) == 2:
            url = url[:url.find('=') + 1] + number[1]
        else:
            url = url[:url.find('=')+1] + number[0]
    except:
        url = url[:url.find('=') + 1] + str(int(number)/2)

# Python_challenge_4
