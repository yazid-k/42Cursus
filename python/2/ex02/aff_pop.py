from load_csv import load
import matplotlib.pyplot as plt


def convert_to_int(value):
    if value[-1] == 'M':
        return int(float(value[:-1]) * 1_000_000)
    elif value[-1] == 'k':
        return int(float(value[:-1]) * 1_000)
    else:
        return int(value)


def main():
    df = load("population_total.csv")
    df.describe()
    france = df[df["country"] == "France"]
    belgium = df[df["country"] == "Belgium"]
    years = df.columns[1:]
    france_pop = france.iloc[:, 1:].apply(convert_to_int).values.flatten()
    belgium_pop = belgium.iloc[:, 1:].apply(convert_to_int).values.flatten()

    years_with_gap = [int(year) + 40 for year in years]

    plt.plot(years_with_gap, france_pop, label="France")
    plt.plot(years_with_gap, belgium_pop, label="Belgium")
    plt.title("Population Comparison")
    plt.xlabel("Year")
    plt.ylabel("Population")
    plt.legend()
    plt.show()


if __name__ == "__main__":
    main()
