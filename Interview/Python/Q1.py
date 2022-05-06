def fn1():
    list1 = [1, 2, 3]
    print(id(list1))
    list2 = list1
    list1 += ['a', 'b', 'c']
    print(id(list1))
    print(list1)
    print(list2)


def fn2():
    list1 = [1, 2, 3]
    print(id(list1))
    list2 = list1
    list1 = list1 + ['a', 'b', 'c']
    print(id(list1))
    print(list1)
    print(list2)

print('calling first function')
fn1()
print('calling second function')
fn2()
