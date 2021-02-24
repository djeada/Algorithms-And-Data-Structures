import pygame
import sys
import random
import math

numberOfElementsHorizontal = 16
numberOfElementsVertical = 16

class Node:
	def __init__(self, x, y):
		self.isBorder = False
		self.distanceTillEnd = float("inf")
		self.distanceFromStart = float("inf")
		self.x = x
		self.y = y
		self.neighbours = []
		self.parent = None

def findNeighbours(x, y, width, height):
	pos = []
	for i in range(-1,2):
		for j in range(-1,2):
			if not (i == 0 and j == 0):
				if not (y + i < 0 or y + i >= height):
					if not (x + j < 0 or x + j >= width):
						pos.append((x+j,y+i))
	return pos

def distance(nodeA, nodeB):
	return math.sqrt((nodeA.x - nodeB.x)**2  + (nodeA.y - nodeB.y)**2)

def sortByGlobalDistance(listOfNodes):
	
	if len(listOfNodes) <= 1:
		return listOfNodes
    
	else:
		return sortByGlobalDistance([node for node in listOfNodes[1:] if node.distanceTillEnd < listOfNodes[0].distanceTillEnd]) + \
			   [listOfNodes[0]] + \
			   sortByGlobalDistance([node for node in listOfNodes[1:] if node.distanceTillEnd >= listOfNodes[0].distanceTillEnd])

def solveAStar(screen, width, height):
	nodeCurrent = nodeStart
	nodeStart.distanceFromStart = 0
	nodeStart.distanceTillEnd = distance(nodeStart, nodeEnd)
	visited = []
	
	notVisited = []
	notVisited.append(nodeStart)
	
	while notVisited and nodeCurrent != nodeEnd:

		notVisited = sortByGlobalDistance(notVisited)	
		
		while notVisited and notVisited[0] in visited:
			del notVisited[0]

		if not notVisited:
			break

		nodeCurrent = notVisited[0];
		visited.append(nodeCurrent)
			
		if nodeCurrent != nodeStart and nodeCurrent != nodeEnd:
			drawField(screen, (227,207,87), nodeCurrent.x*width, nodeCurrent.y*height, width -1, height-1)
				
		for neighbour in nodeCurrent.neighbours:
			if neighbour not in visited and not neighbour.isBorder:
				notVisited.append(neighbour)
				if neighbour != nodeStart and neighbour != nodeEnd:
					drawField(screen, (227,207,87), neighbour.x*width, neighbour.y*height, width -1, height-1)

			newDistance = nodeCurrent.distanceFromStart + distance(nodeCurrent, neighbour)

			if newDistance < neighbour.distanceFromStart:
				neighbour.parent = nodeCurrent
				neighbour.distanceFromStart = newDistance

				neighbour.distanceTillEnd = neighbour.distanceFromStart + distance(neighbour, nodeEnd)

def drawFinalRoute(screen, width, height):
	nodeCurrent = nodeEnd
	while nodeCurrent != nodeStart:
		nodeCurrent = nodeCurrent.parent
		if nodeCurrent != nodeStart:
			drawField(screen, (125,158,192), nodeCurrent.x*width, nodeCurrent.y*height, width -1, height-1)

nodes = []
for y in range(numberOfElementsVertical):
	for x in range(numberOfElementsHorizontal):
		nodes.append(Node(x, y))
		
for y in range(numberOfElementsVertical):
	for x in range(numberOfElementsHorizontal):
		nodes[x + y*numberOfElementsHorizontal].neighbours = [nodes[j + i*numberOfElementsHorizontal] for j, i in findNeighbours(x, y, numberOfElementsHorizontal, numberOfElementsVertical)]

nodeStart = nodes[4]
nodeEnd = nodes[221]

def drawField(screen, kolor, x, y, width, height):
	kwadrat = pygame.Rect(x, y, width, height)
	pygame.draw.rect(screen, kolor, kwadrat)

def drawGrid(screen, width, height, kolor):
	for y in range(h//width):
		for x in range(w//width):
			drawField(screen, kolor, x*width, y*height, width - 1, height - 1)

screen = pygame.display.set_mode((800, 800))
w, h = pygame.display.get_surface().get_size()
width = w//numberOfElementsHorizontal
height = h//numberOfElementsVertical

drawGrid(screen, width, height, (61,145,64))
drawField(screen, (0,255,255), nodeStart.x*width, nodeStart.y*height, width - 1, height - 1)
drawField(screen, (238,0,0), nodeEnd.x*width, nodeEnd.y*height, width - 1, height - 1)
		
while True:
	solveAStar(screen, width, height)
	drawFinalRoute(screen, width, height)
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			sys.exit()

	pygame.display.update()

