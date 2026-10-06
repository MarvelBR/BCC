import os
import cv2
import numpy as np

digitos = "/home/erick/Área de trabalho/BCC/6ºSemestre/Inteligência Computacional/Tarefa 5/digitos_new"
saida_ocr = "/home/erick/Área de trabalho/BCC/6ºSemestre/Inteligência Computacional/Tarefa 5/ocr.txt"

def zoneamento3x3(imagem):
    h, w = imagem.shape[:2]  # Pega altura e largura

    brancos = []
    pretos = []

    # Divide a altura e largura por 3 para definir o tamanho dos blocos
    altura_bloco = h / 3
    largura_bloco = w / 3

    for i in range(3):
        for j in range(3):
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

    return brancos + pretos

def processar_ocr(caminho, saida):
    linhas_saida = []
    extensoes_validas = ('.png', '.jpg', '.jpeg', '.bmp', '.tif', '.tiff')

    print(f"Lendo imagens de: {caminho}...")

    for root, dirs, files in os.walk(caminho):
        for file in files:
            if file.lower().endswith(extensoes_validas):
                caminho_imagem = os.path.join(root, file)

                # Leitura da imagem conforme carregada do disco (-1 mantém os canais originais)
                imagem = cv2.imread(caminho_imagem, -1)

                if imagem is None:
                    continue

                # Zoneamento 3x3
                atributos = zoneamento3x3(imagem)

                # Rótulo extraído da pasta
                label = os.path.basename(root)

                # Formata os 18 valores + label
                atributos_str = " ".join([str(v) for v in atributos])
                linha = f"{atributos_str} {label}\n"
                linhas_saida.append(linha)

    with open(saida, 'w') as f:
        f.write("B1 B2 B3 B4 B5 B6 B7 B8 B9 P1 P2 P3 P4 P5 P6 P7 P8 P9 Label \n")
        f.writelines(linhas_saida)


    print(f"Finalizado! {len(linhas_saida)} amostras salvas em '{saida}'.")


def main():
    processar_ocr(digitos, saida_ocr)


if __name__ == "__main__":
    main()