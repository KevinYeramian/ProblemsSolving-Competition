class Data:
    def __init__(self, rowNumber, columnNumber, vehiculeNumber, rideNumber, bonusPoint, stepNumber, rides, vehicules):
        self.rowNumber = rowNumber
        self.columnNumber = columnNumber
        self.vehiculeNumber = vehiculeNumber
        self.rideNumber = rideNumber
        self.bonusPoint = bonusPoint
        self.stepNumber = stepNumber
        self.rides = rides
        self.vehicules = vehicules

    def getRowNumber(self):
        return self.rowNumber

    def getColumnNumber(self):
        return self.columnNumber

    def getVehiculeNumber(self):
        return self.vehiculeNumber

    def getRideNumber(self):
        return self.rideNumber

    def getBonusPoint(self):
        return self.bonusPoint

    def getStepNumber(self):
        return self.stepNumber

    def getRides(self):
        return self.rides

    def setRides(self, rides):
        self.rides = rides

    def getVehicules(self):
        return self.vehicules

    def setVehicule(self, vehicule):
        self.vehicules[vehicule.getId()] = vehicule

    def printData(self):
        print("rowNumber: {}".format(self.rowNumber))
        print("columnNumber: {}".format(self.columnNumber))
        print("vehiculeNumber: {}".format(self.vehiculeNumber))
        print("rideNumber: {}".format(self.rideNumber))
        print("bonusPoint: {}".format(self.bonusPoint))
        print("stepNumber: {}".format(self.stepNumber))
        for ride in self.rides:
            ride.printRide()

    def getFirstVehicule(self):
        vehiculebest = self.vehicules[0]
        time = self.vehicules[0].getTime()
        for vehicule in self.vehicules:
            if vehicule.getTime() < time:
                time = vehicule.getTime()
                vehiculebest = vehicule
        return vehiculebest

class Ride:
    def __init__(self, idd, a, b, x, y, s, f):
        self.a = a
        self.b = b
        self.x = x
        self.y = y
        self.s = s
        self.f = f
        self.id = idd
        self.assignedVehicule = -1

    def getStart(self):
        return (self.a, self.b)

    def getEnd(self):
        return (self.x, self.y)

    def getEarliestStart(self):
        return self.s

    def getLatestFinish(self):
        return self.f

    def getId(self):
        return self.id

    def getDistance(self):
        return abs(self.a - self.x) + abs(self.b - self.y)

    def setAssignedVehicule(self, vehiculeID):
        self.assignedVehicule = vehiculeID

    def getAssignedVehicule(self):
        return self.assignedVehicule

    def printRide(self):
        print("{} {} {} {} {} {}".format(self.a, self.b, self.x, self.y, self.s, self.f))

    def distanceToEnd(self, coord):
        return abs(coord[0] - self.x) + abs(coord[1] - self.y)

    def distanceToStart(self, coord):
        return abs(coord[0] - self.a) + abs(coord[1] - self.b)

class Vehicule():
    def __init__(self, idv):
        self.id = idv
        self.rides = []
        self.time = 0
        self.position = (0, 0)

    def getRides(self):
        return self.rides

    def setRides(self, rides):
        self.rides = rides

    def addRides(self, ride):
        self.rides.append(ride)



    def getBestRide(self, rides, data):
        score = []
        for ride in rides:
            if int(ride.getAssignedVehicule()) == -1:
                if (ride.distanceToStart(self.position) + ride.getDistance() + self.time <= ride.getLatestFinish()):
                    temp = ride.getDistance()
                    if self.time + ride.distanceToStart(self.position) < ride.getEarliestStart():
                        temp *= data.getBonusPoint()
                    temp -= ride.distanceToStart(self.position)
                    if self.time + ride.distanceToStart(self.position) < ride.getEarliestStart()-1:
                        temp -= (ride.getEarliestStart() - (self.time + ride.distanceToStart(self.position)))
                    score.append(temp)
                else:
                    score.append(-100000000)
            else:
                score.append(-100000000)

        index = score.index(max(score))
        bestRide = rides[index]
        newTime = 0
        if (bestRide.getAssignedVehicule() == -1):
            if self.time + bestRide.distanceToStart(self.position) < bestRide.getEarliestStart():
                newTime = bestRide.getEarliestStart() + bestRide.getDistance() + 1
            else:
                newTime = bestRide.distanceToStart(self.position) + bestRide.getDistance() + self.time + 1
            self.time = newTime
            self.position = bestRide.getEnd()

            bestRide.setAssignedVehicule(int(self.id))
            self.rides.append(bestRide)
            rides[index] = bestRide
        return rides

    def getTime(self):
        return self.time

    def setTime(self, time):
        self.time = time

    def setPosition(self, position):
        self.position = position

    def getId(self):
        return self.id
