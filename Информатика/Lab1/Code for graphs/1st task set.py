import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)

with open ('Set1.txt') as f2:
  y2 = [[float(number) for number in line.split()] for line in f2]


plt.plot(x, y2, 'g--', label=r'$set$')


plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.savefig('1st task set.png')
plt.show()
