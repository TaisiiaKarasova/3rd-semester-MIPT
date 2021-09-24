import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)


with open ('Segment_plus_Set1.txt') as f3:
  y3 = [[float(number) for number in line.split()] for line in f3]

plt.plot(x, y3, 'b--', label=r'$set \; plus \; segment}$')


plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.savefig('1st task segment plus set.png')
plt.show()
