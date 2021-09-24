import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)

with open ('Discete1.txt') as f5:
  y5 = [[float(number) for number in line.split()] for line in f5]

plt.plot(x, y5, '--', label=r'$discrete$')

plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.savefig('1st task discrete.png')
plt.show()
