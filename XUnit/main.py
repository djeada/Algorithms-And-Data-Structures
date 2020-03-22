
def test1():
    print('Test1')
    assert True

def test2():
    print('Test2')
    assert True

def test_Rando():
    print('Rando')
    assert True


#Functions
def setup_function(function):
    if function == test1:
        print("\nSetting up test1!")
    elif function == test2:
        print("\nSetting up test2!")
    else:
        print("\nSetting up unknown test!")

def teardown_function(function):
    if function == test1:
        print("\nTearing down test1!")
    elif function == test2:
        print("\nTearing down test2!")
    else:
        print("\nSetting up unknown test!")

#Modules
def setup_module(function):
    print('Setup Module')

def teardown_module(function):
    print('Teardown module')

#Classes
class TestClass:
    @classmethod
    def setup_class(cls):
        print("Setup TestClass!")

    @classmethod
    def teardown_class(cls):
        print("Teardown TestClass!")

    def setup_method(function):
        if function == test1:
            print("\nSetting up test1!")
        elif function == test2:
            print("\nSetting up test2!")
        else:
            print("\nSetting up unknown test!")

    def teardown_method(function):
        if function == test1:
            print("\nTearing down test1!")
        elif function == test2:
            print("\nTearing down test2!")
        else:
            print("\nSetting up unknown test!")