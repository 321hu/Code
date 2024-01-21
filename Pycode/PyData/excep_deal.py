def cal(x, y):
    if y == 0:
        raise ValueError("Division Error!")
    return x/y

if __name__ == '__main__':
    print('hello')
    cal(2, 0)
    print('exit')