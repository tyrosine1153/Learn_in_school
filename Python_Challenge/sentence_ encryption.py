def encryption(sentence, number):
    output_sentence = ''
    for alphabet in sentence:
        alphabet_as_int = ord(alphabet) + number
        if alphabet_as_int > 122:
            alphabet_as_int -= 26
        output_sentence += str(chr(alphabet_as_int))
    return output_sentence


def decryption(sentence, number):
    output_sentence = ''
    for alphabet in sentence:
        alphabet_as_int = ord(alphabet) - number
        if alphabet_as_int < 33:
            alphabet_as_int += 94
        output_sentence += str(chr(alphabet_as_int))
    return output_sentence


def encryption_pyc(sentence):
    output_sentence = ''
    for alphabet in sentence:
        if 97 <= ord(alphabet) <= 122:
            alphabet_as_int = ord(alphabet) + 2
            if alphabet_as_int > 122:
                alphabet_as_int -= 26
            output_sentence += str(chr(alphabet_as_int))
        else:
            output_sentence += alphabet
    return output_sentence


def decryption_pyc(sentence):
    output_sentence = ''
    for alphabet in sentence:
        if 97 <= ord(alphabet) + 2 <= 122:
            alphabet_as_int = ord(alphabet) - 2
            if alphabet_as_int < 33:
                alphabet_as_int += 94
            output_sentence += str(chr(alphabet_as_int))
        else:
            output_sentence += alphabet

    return output_sentence


if __name__ == '__main__':
    choose = input("1. 일반\n2. 파이썬챌린지\n: ")
    input_sentence = input("암호화할 평문을 입력하세요 : ")

    if choose == '1':
        input_number = int(input("변경할 만큼의 숫자를 입력하세요 : "))
        output = encryption(input_sentence, input_number)
    elif choose == '2':
        output = encryption_pyc(input_sentence)
    print(f"암호화 완료 : {output}")

    if choose == '1':
        output = decryption(output, input_number)
    elif choose == '2':
        output = decryption_pyc(output)
    print(f"복호화 완료 : {output}")
