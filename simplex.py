import numpy as np

def createZJ(l,cb) : 
    zj = []
    for i in range(len(l[0])-1) :
        sum = 0
        for j in range(len(cb)) : 
            # print("l[:,i][j]", l[:,i][j],"cb[j]",cb[j])
            temp = l[:,i][j]*cb[j]
            sum+=temp
            # print(sum)

        zj.append(sum)
    return zj

def indexOfSelectCol(zj,cj) :
    zjCj = []
    for i in range(len(zj)) :
        # print(zj[i],", ",cj[i])
        zjCj.append(zj[i]-cj[i])
        
    # print(zjCj)
    pos = zjCj.index(min(zjCj))
    return pos

def createRatio(solu,selectCol) : 
    result = [solu[i]/selectCol[i] for i in range(len(solu))]
    return result

def indexOfSelectRow(l) : 
    pos = l.index(min([i for i in l if i > 0]))
    return pos

#       Main
z = np.array([6,4])

signs = []
solution = []

solution1 = 2
c1= [-2,1]
sign1 = 0    # 0 for <=, 1 for >=, 2 for =
signs.append(sign1)
solution.append(solution1)

solution2 = 2
c2 = [1,-1]
sign2 = 0 
signs.append(sign2)
solution.append(solution2)

solution3 = 9
c3 = [3,2]
sign3 = 0 
signs.append(sign3)
solution.append(solution3)

l = [c1,c2,c3]

constraints = np.array(l)
signs = np.array([signs])
solution = np.array([solution])


ident = np.identity(len(constraints), dtype = int)
solution = solution.transpose()
final = np.concatenate((constraints, ident, solution), axis = 1)
print(final)

cj = np.append(z,[0,0,0])
cb = [0,0,0]



zj = createZJ(final,cb)
selectColPos = indexOfSelectCol(zj,cj)
# print(final)
selectCol = final[:,selectColPos]
# print(selectCol)

solu = final[:,len(final[0])-1]
# print(solu)

ratio = createRatio(solu,selectCol)
print(ratio)

selectRowPos = indexOfSelectRow(ratio)
print(selectRowPos)