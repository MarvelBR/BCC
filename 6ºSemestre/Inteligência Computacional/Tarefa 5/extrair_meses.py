import os
import cv2
import numpy as np

meses = "/home/erick/Área de trabalho/BCC/6ºSemestre/Inteligência Computacional/Tarefa 5/Base de Dados - Meses do Ano"
saida_meses = "/home/erick/Área de trabalho/BCC/6ºSemestre/Inteligência Computacional/Tarefa 5/meses.txt"

def zoneamento3x6(imagem):
    h, w = imagem.shape[:2]  # Pega altura e largura

    brancos = []
    pretos = []

    # Divide a altura por 3 e a largura por 6 para criar a grade 3x6
    altura_bloco = h / 3
    largura_bloco = w / 6

    for i in range(3):
        for j in range(6):
            # Limites de cada bloco
            y_inicio = int(round(i * altura_bloco))
            y_fim = int(round((i + 1) * altura_bloco))
            x_inicio = int(round(j * largura_bloco))
            x_fim = int(round((j + 1) * largura_bloco))

            # Fatiamento direto da imagem
            bloco = imagem[y_inicio:y_fim, x_inicio:x_fim]

            q_brancos = np.count_nonzero(bloco > 0)
            q_pretos = np.count_nonzero(bloco == 0)

            brancos.append(q_brancos)
            pretos.append(q_pretos)

    # Retorna 18 brancos + 18 pretos = 36 atributos
    return brancos + pretos


def processar_meses(caminho, saida):
    linhas_saida = []
    extensoes_validas = ('.png', '.jpg', '.jpeg', '.bmp', '.tif', '.tiff')

    print(f"Lendo imagens de: {caminho}...")

    for root, dirs, files in os.walk(caminho):
        for file in files:
            if file.lower().endswith(extensoes_validas):
                caminho_imagem = os.path.join(root, file)

                # Pega apenas o nome do arquivo sem a extensão (ex: a1.bmp -> a1)
                label = os.path.splitext(file)[0]

                if label[0] == "a":
                    if label[1] == "b":
                        label = "Agosto"
                    else:
                        label = "Abril"

                elif label[0] == "d":
                    label = "Dezembro"

                elif label[0] == "f":
                    label = "Fevereiro"

                elif label[0] == "j":
                    if label[1] == "d":
                        label = "Junho"

                    elif label[1] == "t":
                        label = "Julho"

                    else:
                        label = "Janeiro"

                elif label[0] == "m":
                    if label[1] == "d":
                        label = "Maio"

                    else:
                        label = "Março"

                elif label[0] == "n":
                    label = "Novembro"

                elif label[0] == "o":
                    label = "Outubro"

                elif label[0] == "s":
                    label = "Setembro"

                else:
                    label = "Mês"

                # Leitura da imagem mantendo os canais originais
                imagem = cv2.imread(caminho_imagem, -1)

                if imagem is None:
                    continue

                # Zoneamento 3x6
                atributos = zoneamento3x6(imagem)

                # Formata os 36 valores + label
                atributos_str = " ".join([str(v) for v in atributos])
                linha = f"{atributos_str} {label}\n"
                linhas_saida.append(linha)

    with open(saida, 'w') as f:
        f.write("B1 B2 B3 B4 B5 B6 B7 B8 B9 B10 B11 B12 B13 B14 B15 B16 B17 B18 P1 P2 P3 P4 P5 P6 P7 P8 P9 P10 P11 P12 P13 P14 P15 P16 P17 P18 Label \n")
        f.writelines(linhas_saida)

    print(f"Finalizado! {len(linhas_saida)} amostras salvas em '{saida}'.")

def main():
    processar_meses(meses, saida_meses)


if __name__ == "__main__":
    main()