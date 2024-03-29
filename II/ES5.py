def encontrar_cobertura_minima(segmentos, a, b):
    segmentos.sort(key=lambda x: x[1])

    cobertura_minima = []
    ponto_atual = a

    while ponto_atual < b:
        melhor_segmento = None
        for segmento in segmentos:
            if segmento[0] <= ponto_atual and segmento[1] > ponto_atual:
                if melhor_segmento is None or segmento[1] > melhor_segmento[1]:
                    melhor_segmento = segmento

        if melhor_segmento is None:
            return "Impossível cobrir o intervalo com os segmentos fornecidos"

        cobertura_minima.append(melhor_segmento)
        ponto_atual = melhor_segmento[1]

    return cobertura_minima

segmentos = []
print("Digite os pares de números em ordem para montar os segmentos.")
x = int(input("Digite o primeiro número do par (digite negativo para encerrar): "))
y = int(input("Digite o segundo número do par (digite negativo para encerrar): "))

while x>=0 or y>=0:
    segmentos.append((x,y))
    x = int(input("Digite o primeiro número do par (digite negativo para encerrar): "))
    y = int(input("Digite o segundo número do par (digite negativo para encerrar): "))

a = int(input("Digite o primeiro número do intervalo: "))
b = int(input("Digite o segundo número do intervalo: "))
    
resultado = encontrar_cobertura_minima(segmentos, a, b)
if isinstance(resultado, list):
    print("Cobertura mínima:")
    for segmento in resultado:
        print(segmento)
else:
    print(resultado)
