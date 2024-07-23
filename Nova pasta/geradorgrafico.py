import matplotlib.pyplot as plt
import numpy as np

# Carregando os dados, pulando a primeira linha (cabeçalho) e usando a vírgula como delimitador
X, Y = np.loadtxt('dados.txt', delimiter=',', skiprows=1, unpack=True)

# Criando o gráfico de dispersão
plt.scatter(X, Y)
plt.title('Gráfico da análise experimental')
plt.xlabel('Size')
plt.ylabel('Time (ms)')
plt.show()