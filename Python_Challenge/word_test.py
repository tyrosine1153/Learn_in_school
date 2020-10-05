word_dict = {}
win_score = 0
retest_score = 0
fail_score = 0
retest = []
with open("sample_to_input.txt", "r", encoding='UTF8') as f:
    while True:
        line = f.readline()
        if not line:
            break
        line = line.strip().split(" ")
        word_dict[line[0]] = line[1]

for eng in word_dict.keys():
    answer = input(f"{eng} : ")
    if word_dict[eng] == answer:
        win_score += 1
        print(f"정답입니다! {eng} {word_dict[eng]}\n")
    else:
        retest.append(eng)
        print(f"오답입니다! {eng} {word_dict[eng]}\n")

if win_score == 10:
    print("------시험이 끝났습니다------")
else:
    print("------재시험을 시작합니다------")

for eng in retest:
    answer = input(f"{eng} : ")
    if word_dict[eng] == answer:
        retest_score += 1
        print(f"정답입니다! {eng} {word_dict[eng]}\n")
    else:
        fail_score += 1
        print(f"오답입니다! {eng} {word_dict[eng]}\n")

print("------시험이 끝났습니다.------\n\n\t+++점수+++")
print(f"\t완벽하게 알고있음 : {win_score}")
print(f"\t알고있음 : {retest_score}")
print(f"\t공부가 필요함 : {fail_score}")