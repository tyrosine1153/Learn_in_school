from sentence_encryption_module import *

if __name__ == '__main__':
    choose = input("1. 일반\n2. 파이썬챌린지\n: ")
    input_sentence = input("암호화할 평문을 입력하세요 : ")

    if choose == '1':
        input_number = int(input("변경할 만큼의 숫자를 입력하세요 : "))
        output_encryp = encryption(input_sentence, input_number)
        output_decryp = decryption(output_encryp, input_number)
    elif choose == '2':
        output_encryp = encryption_pyc(input_sentence)
        output_decryp = decryption_pyc(output_encryp)
    print(f"암호화 완료 : {output_encryp}")
    print(f"복호화 완료 : {output_decryp}")

# Python_challenge_1
