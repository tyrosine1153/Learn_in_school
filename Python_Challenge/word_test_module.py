word_dict = {}
win_score = 0
retest_score = 0
fail_score = 0
retest = []


def open_word_file():
    with open("sample_to_input.txt", "r", encoding='UTF8') as f:
        for line in f:
            line = line.strip().split(" ")
            word_dict[line[0]] = line[1]
    return word_dict


def f_test(win):
    for eng in word_dict.keys():
        answer = input(f"{eng} : ")
        if word_dict[eng] == answer:
            win += 1
            print(f"정답입니다! {eng} {word_dict[eng]}\n")
        else:
            retest.append(eng)
            print(f"오답입니다! {eng} {word_dict[eng]}\n")
    return win


def f_retest(retest_scr, fail):
    for eng in retest:
        answer = input(f"{eng} : ")
        if word_dict[eng] == answer:
            retest_scr += 1
            print(f"정답입니다! {eng} {word_dict[eng]}\n")
        else:
            fail += 1
            print(f"오답입니다! {eng} {word_dict[eng]}\n")
    return retest_scr, fail
