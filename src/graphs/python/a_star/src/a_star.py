"""A* search algorithm implementation."""

from __future__ import annotations

import math
from heapq import heappush, heappop
from itertools import count
from typing import Callable, Any

from graph import Graph, Vertex


def a_star(
    graph: Graph,
    source: Vertex,
    destination: Vertex,
    heuristic: Callable[[Any, Any], float],
) -> float:
    """
    Find the shortest path between source and destination using A* algorithm.

    Args:
        graph: The graph to search.
        source: The starting vertex.
        destination: The target vertex.
        heuristic: A function that estimates the distance between two vertex values.

    Returns:
        The shortest distance from source to destination, or infinity if no path exists.
    """
    if not (graph.contains(source) and graph.contains(destination)):
        return math.inf

    distance_from_source: dict[Vertex, float] = {}
    distance_till_destination: dict[Vertex, float] = {}

    for vertex in graph.vertices():
        distance_from_source[vertex] = math.inf
        distance_till_destination[vertex] = math.inf

    distance_from_source[source] = 0
    distance_till_destination[source] = heuristic(source.value, destination.value)

    # The counter breaks ties so vertices themselves never need to be comparable.
    counter = count()
    open_set: list[tuple[float, int, Vertex]] = []
    heappush(open_set, (distance_till_destination[source], next(counter), source))

    while open_set:
        priority, _, current = heappop(open_set)

        # Skip stale entries: a better path to this vertex was found after the push.
        if priority > distance_till_destination[current]:
            continue

        if current == destination:
            return distance_from_source[destination]

        for edge in graph.edges_from_vertex(current):
            tentative_distance_from_source = (
                distance_from_source[current] + edge.distance
            )

            if tentative_distance_from_source < distance_from_source[edge.destination]:
                distance_from_source[edge.destination] = tentative_distance_from_source
                distance_till_destination[edge.destination] = distance_from_source[
                    edge.destination
                ] + heuristic(edge.destination.value, destination.value)

                # Always push: the previous entry (if any) is now stale and skipped.
                heappush(
                    open_set,
                    (
                        distance_till_destination[edge.destination],
                        next(counter),
                        edge.destination,
                    ),
                )

    return math.inf
