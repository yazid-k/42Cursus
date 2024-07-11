import sys


def parity_check(i):
    if (i % 2 == 0):
        print("I'm Even")
    else:
        print("I'm Odd")


args = sys.argv[1:]


try:
    try:
        i = int(args[0])
    except ValueError:
        raise AssertionError("argument is not an integer")
    if (len(args) > 1):
        raise AssertionError("more than one argument is provided")
except AssertionError as e:
    print(f"{AssertionError.__name__} : {e}")
else:
    parity_check(int(args[0]))
