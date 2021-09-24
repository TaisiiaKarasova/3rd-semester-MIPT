import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10000, 1)
with open ('Segment1.txt') as f1:
  y1 = [[float(number) for number in line.split()] for line in f1]


with open ('Set1.txt') as f2:
  y2 = [[float(number) for number in line.split()] for line in f2]

with open ('Segment_plus_Set1.txt') as f3:
  y3 = [[float(number) for number in line.split()] for line in f3]

with open ('Segment_minus_Set1.txt') as f4:
  y4 = [[float(number) for number in line.split()] for line in f4]

with open ('Discete1.txt') as f5:
  y5 = [[float(number) for number in line.split()] for line in f5]

  
plt.plot(x, y1, 'r--', label=r'$segment$')
plt.plot(x, y2, 'g--', label=r'$set$')
plt.plot(x, y3, 'b--', label=r'$segmet \; plus \; set}$')
plt.plot(x, y4, 'y--', label=r'$segment \; minus \; set}$')
plt.plot(x, y5, '--', label=r'$discrete$')

plt.xlabel(r'$number \; of \; approbations$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; number \; of \; approbations$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('1st task.png')
plt.show()
