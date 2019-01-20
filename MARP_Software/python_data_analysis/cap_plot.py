import numpy as np
import matplotlib.pyplot as plt
plt.figure();
Vsrc = 5.0;
R = 5;
C = 0.000330;
time = np.arange(0, 0.5, 0.0001);
Vcap = Vsrc * np.exp(-time/(R*C));

plt.plot(time, Vcap);
plt.plot(time, Vcap/float(R));
plt.xlabel('time (s)');
