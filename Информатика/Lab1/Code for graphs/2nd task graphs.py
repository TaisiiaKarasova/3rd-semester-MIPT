import numpy as np
import matplotlib.pyplot as plt

with open ('ArgSegment2.txt') as a1:
  x1 = [[float(number) for number in line.split()] for line in a1]
with open ('Segment2.txt') as f1:
  y1 = [[float(number) for number in line.split()] for line in f1]

with open ('ArgSet2.txt') as a2:
  x2 = [[float(number) for number in line.split()] for line in a2]
with open ('Set2.txt') as f2:
  y2 = [[float(number) for number in line.split()] for line in f2]

with open ('ArgSegmentPSet2.txt') as a3:
  x3 = [[float(number) for number in line.split()] for line in a3]
with open ('Segment_plus_Set2.txt') as f3:
  y3 = [[float(number) for number in line.split()] for line in f3]

with open ('ArgSegmentMSet2.txt') as a4:
  x4 = [[float(number) for number in line.split()] for line in a4]
with open ('Segment_minus_Set2.txt') as f4:
  y4 = [[float(number) for number in line.split()] for line in f4]

with open ('ArgDiscrete2.txt') as a5:
  x5 = [[float(number) for number in line.split()] for line in a5]
with open ('Discete2.txt') as f5:
  y5 = [[float(number) for number in line.split()] for line in f5]

  
plt.plot(x1, y1, 'r--', label=r'$segment$')
plt.plot(x2, y2, 'g--', label=r'$set$')
plt.plot(x3, y3, 'b--', label=r'$set \; plus \; segment$')
plt.plot(x4, y4, 'y--', label=r'$set \; minus \; segment$')
plt.plot(x5, y5, '--', label=r'$discrete$')

plt.xlabel(r'$\; set-to-interval \; relation$')
plt.ylabel(r'$probability$')
plt.title(r'$dependence \; of \; probability \; on \; set-to-interval \; relation$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('2n task.png')
plt.show()
