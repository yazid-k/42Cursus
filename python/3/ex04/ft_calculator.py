class calculator:
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        return [V1[i] * V2[i] for i in range(len(V1))]

    def add_vec(V1: list[float], V2: list[float]) -> None:
        return [V1[i] + V2[i] for i in range(len(V1))]

    def sous_vec(V1: list[float], V2: list[float]) -> None:
        return [V1[i] - V2[i] for i in range(len(V1))]
