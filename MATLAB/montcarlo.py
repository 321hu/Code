import random
import math
import numpy as np
import matplotlib.pyplot as plt


Error = []
n_label = range(1000, 10001, 10)
for n in n_label:
# n = 10000
    x = np.random.uniform(0, 2, n)
    y = np.random.uniform(0, 3, n)
    CntNum = 0
    for i in range(n):
        if x[i]*x[i]/4 + y[i]*y[i]/9 <= 1:
            CntNum += 1
    Area = 4*6*CntNum/n
    ExactArea = 6 * math.pi
    Error.append(math.fabs(Area - ExactArea))
plt.plot(n_label, Error, marker='o', linestyle='-', color='b', label='折线图')
# plt.show()