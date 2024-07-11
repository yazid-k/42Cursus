import pandas as pd


def load(path: str) -> pd.DataFrame:
    try:
        df = pd.read_csv(path)
        print(f"Loading dataset of dimensions {df.shape}")
        return df
    except FileNotFoundError:
        print(f"File not found: {path}")
        return None
