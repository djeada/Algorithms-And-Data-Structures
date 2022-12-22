def all_permutations(input_list):
    def _all_permutations(input_list, output_list):
        if len(output_list) == len(input_list):
            result.append(output_list)
            return

        for element in input_list:
            if element not in output_list:
                _all_permutations(input_list, output_list + [element])

    result = []
    _all_permutations(input_list, [])
    return result
