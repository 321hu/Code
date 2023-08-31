# module.py

def some_function():
    print("This is some_function() in module.py")

print("This is the top-level of module.py")

if __name__ == "__main__":
    print("This is being run as the main module.")
    some_function()
elif __name__ == "module":
    print("This is being imported as a module.")
