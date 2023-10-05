import math
import random

x_0 = random.uniform(-0.5*math.pi, 0.5*math.pi)
error = 1e-10
x_1 = math.atan(x_0)
while math.fabs(x_0 - x_1) > error:
    x_0 = x_1
    x_1 = math.atan(x_0)
print(x_0, x_1)