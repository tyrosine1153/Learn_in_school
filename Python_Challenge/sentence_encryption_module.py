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
