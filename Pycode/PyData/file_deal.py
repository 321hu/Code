def make_story(filepath):
    f = open(filepath, 'w')
    f.write("I'm coming!\n")
    f.write("How are you?")
    f.close()

def add_to_story(filepath):
    f = open(filepath, 'a')
    f.write("\nThis is an additional information.")
    f.close()

def print_line_file(filepath):
    '''readline()'''
    f = open(filepath)
    while 1:
        line = f.readline()
        if line:
            print(line, end='')
        else:
            break
    f.close()

def print_line_file2(filepath):
    '''readlines()'''
    f = open(filepath)
    lines = f.readlines()
    print(type(lines))
    for line in lines:
        print(line, end='')
    f.close()

def print_line_file3(filepath):
    '''read()'''
    f = open(filepath)
    context = f.read()
    print(type(context))
    print(context)
    f.close()

def insert_title(title, filepath):
    '''Insert the *title* into the head of the file'''
    f = open(filepath, 'r+')
    tmp = f.read()
    tmp = title + '\n' + tmp
    f.seek(0)
    f.write(tmp)
    f.close()

if __name__ == '__main__':
    # make_story('file_example.txt')
    # add_to_story('file_example.txt')
    # print_line_file('file_example.txt')
    # print_line_file2('file_example.txt')
    # print_line_file3('file_example.txt')
    insert_title('Hey!', 'file_example.txt')