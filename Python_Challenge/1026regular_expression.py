data = ['park 800905-1049118', 'kim 700905-1059117']
number = []

for dta in data:
    div = dta.find(' ')+1
    # 숫자인지 확인
    isnum = 0
    for i in range(div, div+14):
        if dta[i].isdigit():
            isnum += 1
    # 14자 중 '-' 제외 모두 숫자면
    if isnum == 13:
        num = dta[div:div+7]+'*******'
        number.append(dta[:div]+num)

print(number)
"""
입력 유효성 체크, 특정 값 추출, 문자열 바꾸기에서 사용 
pattern 을 사용
'park 800905-1049118', 'kim 700905-1059117'
"""
