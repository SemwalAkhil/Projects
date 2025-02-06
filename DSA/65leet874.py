class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        # 0 north 1 east 2 south 3 west
        pos = [0,0]
        curDir = 0
        tup = (0,)
        for i in commands:
            if (i > 0):
                if(curDir == 0):
                    for j in range(i):
                        if ([pos[0],j] in obstacles):
                            pos[1] += j-1
                            break
                    else:
                        pos[1] += j
                elif(curDir == 1):
                    for j in range(i):
                        if (j,[pos[1]] in obstacles):
                            pos[0] += j-1
                            break
                    else:
                        pos[0] += j
                elif(curDir == 2):
                    if(curDir == 0):
                        for j in range(i):
                            if ([pos[0],j] in obstacles):
                                pos[1] -= j-1
                                break
                        else:
                            pos[1] -= j
                else:
                    for j in range(i):
                        if (j,[pos[1]] in obstacles):
                            pos[0] -= j-1
                            break
                    else:
                        pos[0] -= j
            elif (i == -1):
                curDir = (curDir+1)%4 
            else:
                curDir = (curDir-1)%4
            tup += ((pos[0]**2)+(pos[1]**2),)
        return max(tup)

a = Solution()
commands = [-2,-1,8,9,6]
obstacles = [[-1,3],[0,1],[-1,5],[-2,-4],[5,4],[-2,-3],[5,-1],[1,-1],[5,5],[5,2]]
print(a.robotSim(commands,obstacles))