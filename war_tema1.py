# Versão em Python do Tema 1 - War Estruturado

class Pais:
    def __init__(self, id_, nome):
        self.id = id_
        self.nome = nome
        self.dono = 0
        self.exercitos = 0
        self.vizinhos = []

def carregar_mapa(arquivo):
    paises = []
    try:
        with open(arquivo, "r", encoding="utf-8") as f:
            for linha in f:
                linha = linha.strip()
                if not linha:
                    continue

                partes = linha.split(";")
                id_ = int(partes[0])
                nome = partes[1]
                p = Pais(id_, nome)

                if len(partes) > 2:
                    for v in partes[2].split(","):
                        p.vizinhos.append(int(v))

                paises.append(p)

    except FileNotFoundError:
        return None

    return paises

def listar_paises(paises):
    print(f"Lista de {len(paises)} pais(es):")
    for p in paises:
        viz = " ".join(str(v) for v in p.vizinhos)
        print(f"ID {p.id} - {p.nome} | dono: {p.dono} | exércitos: {p.exercitos} | vizinhos: {viz}")

def distribuir_paises(paises, jogadores):
    for i, p in enumerate(paises):
        owner = (i % len(jogadores)) + 1
        p.dono = owner
        p.exercitos = 1
        jogadores[owner-1]["exercitos"] += 1

def main():
    paises = carregar_mapa("mapa.txt")
    if not paises:
        print("Erro ao carregar mapa.txt")
        return

    print(f"Mapa carregado: {len(paises)} pais(es)")

    qtd = int(input("Quantos jogadores? (2-6): "))
    jogadores = []

    for i in range(qtd):
        nome = input(f"Nome do jogador {i+1}: ").strip() or f"Jogador{i+1}"
        jogadores.append({"id": i+1, "nome": nome, "exercitos": 0})

    distribuir_paises(paises, jogadores)

    print("\n--- Estado Inicial ---")
    listar_paises(paises)

    print("\nJogadores:")
    for j in jogadores:
        print(j)

if __name__ == "__main__":
    main()
