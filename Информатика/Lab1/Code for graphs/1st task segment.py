import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)
with open ('Segment1.txt') as f1:
  y1 = [[float(number) for number in line.split()] for line in f1]


  
plt.plot(x, y1, 'r--', label=r'$segment$')


plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.savefig('1st task segment.png')
plt.show()
