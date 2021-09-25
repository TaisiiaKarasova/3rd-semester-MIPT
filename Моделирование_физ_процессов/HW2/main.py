#!/usr/bin/env python
# coding: utf-8

# # Фигуры Лиссажу

# In[39]:


import numpy as np
import matplotlib.pyplot as plt

delta = [np.pi / 4, np.pi / 6, np.pi / 8, np.pi / 3]
omega_1 = [2 * np.pi / 3, np.pi, np.pi / 4, 2 * np.pi / 5]
omega_2 = [2 * np.pi / 5, 2 * np.pi / 3, 2 * np.pi / 13, 2 * np.pi / 9]
A = [50, 40, 30, 70]
B = [40, 70, 60, 30]

t = np.linspace(0.0, 200, 1000)

x = [[1000], [1000], [1000], [1000]]
y = [[1000], [1000], [1000], [1000]]

x1 = A[0] * np.sin(omega_1[0] * t + delta[0])
y1 = B[0] * np.cos(omega_2[0] * t)

for i in range(4):
    x[i] = A[i] * np.sin(omega_1[i] * t + delta[i])
    y[i] = B[i] * np.cos(omega_2[i] * t)

fig, axs = plt.subplots(2, 2)
axs[0, 0].plot(x[0], y[0])
axs[0, 0].set_title(r'$\omega_1 / \omega_2 = 3/5, \; A/B = 5/4, \; \delta = \pi/4$')
plt.grid(True)
axs[0, 1].plot(x[1], y[1], 'tab:orange')
axs[0, 1].set_title(r'$\omega_1 / \omega_2 = 2/3, \; A/B = 4/7 \; \delta = \pi/6$')
plt.grid(True)
axs[1, 0].plot(x[2], y[2], 'tab:green')
axs[1, 0].set_title(r'$\omega_1 / \omega_2 = 8/13, \; A/B = 1/2 \; \delta = \pi/8$')
axs[1, 1].plot(x[3], y[3], 'tab:red')
axs[1, 1].set_title(r'$\omega_1 / \omega_2 = 5/9, \; A/B = 7/3 \; \delta = \pi/3$')


# Hide x labels and tick labels for top plots and y ticks for right plots.
for ax in axs.flat:
    ax.label_outer()


# # Массив по шаблону

# In[49]:


import numpy as np

b = 2*np.eye(10, dtype=np.float)
b -= np.diag(np.ones([9],dtype=np.float), 1)
b -= np.diag(np.ones([9],dtype=np.float), -1)
print(b)


# # МНК

# In[43]:


import numpy as np
import matplotlib.pyplot as plt

with open ('x.txt') as fx:
  x0 = [[float(number) for number in line.split()] for line in fx]


with open ('y.txt') as fy:
  y0 = [[float(number) for number in line.split()] for line in fy]

x = [0] * np.size(x0)
y = [0] * np.size(y0)
for i in range (np.size(x0)):
    x[i] = x0[i][0]
    
for i in range (np.size(y0)):
    y[i] = y0[i][0]


    
plt.plot(x, y, 'ro')
p, v = np.polyfit(x, y, deg=1)
x_general = np.linspace(0.00, 0.25, 100)
y_general = p * x_general + v

plt.plot(x_general, y_general)

