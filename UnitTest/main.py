import pytest

def fizzbuzz(n):
    """
    Returns whether Fizz or Buzz or Fizzbuzz or number.
    """
    if n % 15 == 0:
        value = "FizzBuzz"

    elif n % 5 == 0:
        value = "Buzz"

    elif n % 3 == 0:
        value = "Fizz"

    else:
        value = "%d" % n

    return value

def main():
    """
    Prints numbers from 1 to 100. But for multiples of three print "Fizz"
    instead of the number and for the multiples of five print "Buzz". For
    numbers which are multiples of both three and five print "FizzBuzz".
    """
    # 1..100 inclusive
    for n in range(1, 100+1):
        print(fizzbuzz(n))

def tests():
    assert "Fizz" == fizzbuzz(3)
    assert "Buzz" == fizzbuzz(5)
    assert "FizzBuzz" == fizzbuzz(15)

    assert "1" == fizzbuzz(1)
    assert "2" == fizzbuzz(2)
    assert "7" == fizzbuzz(7)
    assert "8" == fizzbuzz(8)

if __name__ == '__main__':
    # for educational-purpose run tests first
    tests()
    main()