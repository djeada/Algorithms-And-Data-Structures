def add_string_numbers(s1: str, s2: str) -> str:

    decimal_places = 0

    def is_float(s: str) -> bool:
        return "." in s

    def number_of_decimal_places(s: str) -> int:
        return len(s) - s.index(".") - 1

    if is_float(s1) or is_float(s2):
        # check which number has more decimal places and add zeros to the other
        # keep track of the number of decimal places
        decimal_places_1 = number_of_decimal_places(s1)
        decimal_places_2 = number_of_decimal_places(s2)
        if is_float(s1) and is_float(s2):
            decimal_places = max(decimal_places_1, decimal_places_2)
            s1 = s1.replace(".", "")
            s2 = s2.replace(".", "")
            s1 += "0" * (decimal_places - decimal_places_1)
            s2 += "0" * (decimal_places - decimal_places_2)
        elif is_float(s1):
            decimal_places = decimal_places_1
            s1 = s1.replace(".", "")
            s2 += "0" * decimal_places

        elif is_float(s2):
            decimal_places = decimal_places_2
            s2 = s2.replace(".", "")
            s1 += "0" * decimal_places

    # we can't convert to int, because the numbers might be too big and it will overflow
    # so we'll add the numbers digit by digit
    # we'll start from the end of the strings

    result = ""
    carry = 0

    i = len(s1) - 1
    j = len(s2) - 1

    while i >= 0 or j >= 0:
        digit_1 = int(s1[i]) if i >= 0 else 0
        digit_2 = int(s2[j]) if j >= 0 else 0
        sum = digit_1 + digit_2 + carry
        carry = sum // 10
        result = str(sum % 10) + result
        i -= 1
        j -= 1

    if carry > 0:
        result = str(carry) + result

    if decimal_places > 0:
        result = result[:-decimal_places] + "." + result[-decimal_places:]

    return result
