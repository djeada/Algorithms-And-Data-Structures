def count_ways_to_climb_basic(num_steps):
    if num_steps < 0:
        return 0

    if num_steps == 0:
        return 1

    return (
        count_ways_to_climb_basic(num_steps - 3)
        + count_ways_to_climb_basic(num_steps - 2)
        + count_ways_to_climb_basic(num_steps - 1)
    )


def count_ways_to_climb_memo(num_steps, ways_to_climb=dict()):
    if num_steps < 0:
        return 0

    if num_steps == 0:
        return 1

    if num_steps in ways_to_climb:
        return ways_to_climb[num_steps]

    ways_to_climb[num_steps] = (
        count_ways_to_climb_memo(num_steps - 1, ways_to_climb)
        + count_ways_to_climb_memo(num_steps - 2, ways_to_climb)
        + count_ways_to_climb_memo(num_steps - 3, ways_to_climb)
    )
    return ways_to_climb[num_steps]


def count_ways_to_climb_table(n):
    if n < 0:
        return 0

    if n == 0:
        return 1

    table = [0] * (n + 1)
    table[0] = 1

    for i in range(1, n + 1):
        table[i] = table[i - 1] + table[i - 2] + table[i - 3]

    return table[n]
