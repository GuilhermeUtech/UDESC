def funcao(atual):
    aux =  (atual*atual)
    aux2 = aux - 4
    return aux2

def funcaoDerivada(atual):
    return atual*2


atual = float(input("Digite um valor para usar o método."))
n = int(input("Digite o número de iterações"))
proximo=aux=iteracao=temp = 0

while(iteracao < n):
    proximo = atual - (funcao(atual)/funcaoDerivada(atual))
    atual = proximo
    iteracao = iteracao+1
    print(atual)












