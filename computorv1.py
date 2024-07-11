import sys

def parse_equation(equation):
    terms = equation.replace(" ", "").replace("-", "+-").split("=")
    left_terms = terms[0].split("+")
    right_terms = terms[1].split("+")
    right_terms = list(filter(None, right_terms))
    left_terms = list(filter(None, left_terms))
    coefficients = {0: 0, 1: 0, 2: 0}  # Supports up to 2nd degree polynomial equations.
    if (left_terms == right_terms):
        print("The equation is always true.")
        sys.exit(1)
    for term in left_terms + right_terms:
        if 'X^' in term:
            coef, power = term.split('*X^')
            if int(power) > 2:
                print("The polynomial degree is strictly greater than 2, I can't solve.")
                sys.exit(1)
            power = int(power)
            if term in left_terms:
                coefficients[power] += float(coef)
            else:
                coefficients[power] -= float(coef)
        else:
            if term in left_terms:
                coefficients[0] += float(term)
            else:
                coefficients[0] -= float(term)
    return coefficients

def solve_linear(a, b):
    return -b / a

def solve_quadratic(a, b, c):
    discriminant = b**2 - 4*a*c
    if discriminant > 0:
        x1 = (-b + discriminant**0.5) / (2*a)
        x2 = (-b - discriminant**0.5) / (2*a)
        return (x1, x2, "Discriminant is strictly positive, the two solutions are:")
    elif discriminant == 0:
        x = -b / (2*a)
        return (x, x, "Discriminant is zero, there is one solution:")
    else:
        return (None, None, "Discriminant is strictly negative, there are no real solutions.")

def display_equation(coefficients):
    equation = ""
    for power, coef in coefficients.items():
        if coef == 0:
            continue
        if coef > 0:
            equation += " + " if equation else ""
        else:
            equation += " - "
        equation += str(abs(coef))
        equation += f" * X^{power}"


    equation = equation.replace(' ', '').replace("+", " + ").replace("-", " - ").replace("*", " * ")
    equation = equation + " = 0"
    return "Reduced form: " + equation

def main():
    if len(sys.argv) != 2:
        print("Usage: python computorv1.py '<equation>'")
        return

    equation = sys.argv[1]
    print(f"Original equation: {equation}")

    coefficients = parse_equation(equation)
    print(f"Parsed coefficients: {coefficients}")
    print(display_equation(coefficients))

    degree = max([power for power, coef in coefficients.items() if coef != 0])
    print(f"Polynomial degree: {degree}")

    if degree > 2:
        print("The polynomial degree is strictly greater than 2, I can't solve.")
        return

    if degree == 1:
        print("Solving a linear equation...")
        solution = solve_linear(coefficients[1], coefficients[0])
        print(f"The solution is:\n{solution}")
    elif degree == 2:
        print("Solving a quadratic equation...")
        x1, x2, message = solve_quadratic(coefficients[2], coefficients[1], coefficients[0])
        print(message)
        if x1 is not None:
            print(f"Roots:\n{x1}\n{x2}")

if __name__ == "__main__":
    main()
