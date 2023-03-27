import numpy as np

z = np.array([[2,4]])

signs = np.array([])
rhs = np.array([])

c1= [-2,1]
c2 = [1,-1]
c3 = [3,2]
l = [c1,c2,c3]
constraints = np.array(l)

print("Constraints : \n",constraints)

