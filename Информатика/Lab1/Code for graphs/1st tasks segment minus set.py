import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)
with open ('Segment_minus_Set1.txt') as f4:
  y4 = [[float(number) for number in line.split()] for line in f4]
plt.plot(x, y4, 'y--', label=r'$segment \; minus \; set}$')


plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.savefig('1st task segment minus set.png')
plt.show()

