#!/usr/bin/env python3
import numpy as np
import sys
from data import Data, Vehicule, Ride
from operator import attrgetter

def reader(filename):
    with open(filename) as f:
        lines = f.readlines()
    lines = [line.strip().split(' ') for line in lines]
    lines = [(int(x) for x in line) for line in lines]
    R, C, F, N, B, T = lines[0]

    rides = []
    for i in range(1, len(lines)):
        a, b, x, y, s, f = lines[i]
        rides.append(Ride(i-1, a, b, x, y, s, f))

    vehicules = []
    for i in range(F):
        vehicules.append(Vehicule(i))

    data = Data(R, C, F, N, B, T, rides, vehicules)

    return data

def main(filename):
    #print("Reading data")

    data = reader(filename)
    #print("Data read")
    #data.printData()

    outData = solver(data)
    #print("Resolution done")

    printOutputs(outData)

def solver(data):
    rides = data.getRides()

    for i in range(len(rides)):
        rides = data.getRides()
        vehicule = data.getFirstVehicule()
        
        rides = vehicule.getBestRide(rides, data)
        data.setRides(rides)
        data.setVehicule(vehicule)



    return data

def printOutputs(data):
    #print("Outputs")
    for vehicule in data.getVehicules():
        if len(vehicule.getRides()) >= 0:
            s = str(len(vehicule.getRides()))
            for ride in vehicule.getRides():
                s += " " + str(ride.getId())
            print(s)

if __name__ == '__main__':
    if(len(sys.argv) > 1):
        main(sys.argv[1])
    else:
        print("Missing parameter filename")
