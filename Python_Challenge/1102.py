import re

dish_list = '''
5
시리얼/우유(2.5.6.13.)
황도샐러드/드레싱(1.2.5.6.11.12.13.)
크리스피핫도그(미니)/케첩(1.2.5.6.10.12.15.18.)허니버터아몬드(2.5.13.)
* 에너지/단백질/칼슘/철분 
546.2/15/495.5/4.9
'''
dish_list = dish_list[:dish_list.find('*')]
meal_pattern = re.compile(r"[가-힣]*[(]*[가-힣]+[)]*[/가-힣]*[(]*[가-힣]+[)]*")
temp = re.findall(meal_pattern, dish_list)
print(temp)
