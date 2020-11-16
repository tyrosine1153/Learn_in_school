import pickle
import requests
"""
url = 'http://www.pythonchallenge.com/pc/def/banner.p'
text = requests.get(url).text
print(text)
"""
with open(r'banner.p', 'rb') as file:
    data_list = pickle.load(file)
"""
    data_list = []
    while True:
        try:
            data = pickle.load(file)
        except EOFError:
            break
        else:
            data_list.append(data)
data_list = data_list[0]
"""
for line in data_list:
    for dot, num in line:
        print(dot * num, end='')
    print('')

# Python_challenge_5
