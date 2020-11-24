import re
import zipfile

zip_path = r'C:\Users\jungm\Downloads\channel.zip'
pattern = re.compile(r'[0-9]+')
zip_to_open = zipfile.ZipFile(zip_path)

start = '90052.txt'
answer = ''

while True:
    text = zip_to_open.read(start).decode()
    answer += zip_to_open.getinfo(start).comment.decode()
    try:
        start = re.findall(pattern, text)[0] + '.txt'
    except:
        break

print(answer)

# Python_challenge_6
