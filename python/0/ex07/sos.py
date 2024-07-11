import sys


def main():
    """
    Convert a string into Morse code and print the result.

    The function takes a single command-line argument, which
    should be a string.
    It converts each character of the string into its corresponding Morse code
    representation and prints the result.

    If the number of command-line arguments is not equal to 1,
    or if the argument
    contains any non-alphanumeric characters (except spaces), an AssertionError
    is raised.

    Morse code is represented using dots (.) and dashes (-). Each character is
    separated by a space.

    Example:
    >>> python sos.py "HELLO WORLD"
    .... . .-.. .-.. --- / .-- --- .-. .-.. -..
    """
    NESTED_MORSE = {'A': '.-', 'B': '-...',
                    'C': '-.-.', 'D': '-..', 'E': '.',
                    'F': '..-.', 'G': '--.', 'H': '....',
                    'I': '..', 'J': '.---', 'K': '-.-',
                    'L': '.-..', 'M': '--', 'N': '-.',
                    'O': '---', 'P': '.--.', 'Q': '--.-',
                    'R': '.-.', 'S': '...', 'T': '-',
                    'U': '..-', 'V': '...-', 'W': '.--',
                    'X': '-..-', 'Y': '-.--', 'Z': '--..',
                    '1': '.----', '2': '..---', '3': '...--',
                    '4': '....-', '5': '.....', '6': '-....',
                    '7': '--...', '8': '---..', '9': '----.',
                    '0': '-----', ' ': '/ '}
    args = sys.argv[1:]
    try:
        if (len(args) != 1):
            raise AssertionError("wrong number of arguments")
        for i in args[0]:
            if (not i.isalnum() and not i.isspace()):
                raise AssertionError("the arguments are bad")
    except AssertionError as e:
        print(f"{AssertionError.__name__} : {e}")
    else:
        for i in args[0]:
            print(NESTED_MORSE[i.capitalize()], end=' ')
        print()


if __name__ == "__main__":
    main()
