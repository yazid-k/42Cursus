from load_csv import load
import matplotlib.pyplot as plt


def main():
    df = load("life_expectancy_years.csv")
    if df is None:
        return
    france = df[df["country"] == "France"]
    years = france.columns[1:]
    print(years)
    life_expectancy = france.values[0][1:]
    years_with_gap = [int(year) + 40 for year in years]
    plt.plot(years_with_gap, life_expectancy)
    plt.xlabel("Year")
    plt.ylabel("Life expectancy")
    plt.title("Life expectancy in France")
    plt.show()


if __name__ == "__main__":
    main()
