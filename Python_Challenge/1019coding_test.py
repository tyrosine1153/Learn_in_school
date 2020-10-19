import random
lst = [["선택정렬", "삽입정렬", "버블정렬", "퀵정렬", "병합절렬", "해시", "스택", "큐", "힙", "탐욕(그리디)",
       "그래프", "동적계획(DP)", "이분탐색", "완전탐색(BF)", "너비우선탐색(BFS)", "깊이우선탐색(DFS)"],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
dic = {}
print(lst)
for i in range(1, 21):
    random_int = random.randint(0, 15)
    print(lst[1][random_int])
    if i <= 16:
        while lst[1][random_int] != 0:
            random_int = random.randint(0, 15)
    else:
        while lst[1][random_int] != 1:
            random_int = random.randint(0, 15)
    dic[i] = lst[0][random_int]
    lst[1][random_int] += 1

print(dic)

"""
틀 : 2중 리스트를 이용해 중복 여부를 확인한다
for (int i=0;i<20;i++){
    random = randint(0,16)
    while lst[random][1]!=0:
}
랜덤번째 리스트의 1번째 값이 0이면 실행 아니면 그렇게 될때까지 랜덤번째 변수를 고름
사전에 랜덤번째 리스트의 0번째 값을 넣고 1번째값에 1을 더함
"""