from word_test_module import *

if __name__ == '__main__':
    word_dict = open_word_file()

    win_score = f_test(win_score)

    print(win_score, retest_score, fail_score)
    if win_score != 10:
        print("------재시험을 시작합니다------")
        retest_score, fail_score = f_retest(retest_score, fail_score)

    print("------시험이 끝났습니다.------\n\n\t+++점수+++")
    print(f"\t완벽하게 알고있음 : {win_score}")
    print(f"\t알고있음 : {retest_score}")
    print(f"\t공부가 필요함 : {fail_score}")

# 첫 번째 시험과 재시험을 같은 함수로 묶어서 사용하기
# 코드들을 클래스와 함수로 묶어서 모듈화 하기
