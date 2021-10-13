# Итератор для удаления дубликатов
class Unique(object):
    def __init__(self, items, **kwargs):
        self.data = set()
        self.items=items
        self.iter_ind = 0
        self.ignore_case = kwargs.get('ignore_case', False)
        # Нужно реализовать конструктор
        # В качестве ключевого аргумента, конструктор должен принимать
        # bool-параметр ignore_case,
        # в зависимости от значения которого будут считаться одинаковыми строки
        # в разном регистре
        # Например: ignore_case = True, Aбв и АБВ - разные строки
        #           ignore_case = False, Aбв и АБВ - одинаковые строки, одна из
        #           которых удалится
        # По-умолчанию ignore_case = False

    def __next__(self):
        current = None
        while True:
            if isinstance(self.items, list):
                if self.iter_ind >= len(self.items):
                    raise StopIteration
                else:
                    current = self.items[self.iter_ind]
                    self.iter_ind+=1
                if self.ignore_case and current not in self.data: 
                    self.data.add(current)
                    return current
                elif not self.ignore_case and current.lower() not in set(map(str.lower,self.data)): 
                    self.data.add(current)
                    return current
            else:
                current = next(self.items)
                if self.ignore_case and current not in self.data: 
                    self.data.add(current)
                    return current
                elif not self.ignore_case and current.lower() not in set(map(str.lower,self.data)): 
                    self.data.add(current)
                    return current
               

    def __iter__(self):
        return self


if __name__ == "__main__":
    b = ['a', 'A', 'b', 'B', 'a', 'A', 'b', 'B']
    alist = [1, 1, 1, 1, 1, 2, 2, 2, 2, 2]
    
    for i in Unique(alist): print(i)