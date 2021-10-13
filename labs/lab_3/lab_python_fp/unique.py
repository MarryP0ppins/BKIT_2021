# Итератор для удаления дубликатов
from lab_python_fp.gen_random import gen_random
class Unique(object):
    def __init__(self, items, **kwargs):
        self.data = set()
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

        pass 

    def __next__(self):
        current = None
        while True:
            try:
                current = next(self.data)
            except TypeError:
                if self.iter_ind >= len(self.data):
                    raise StopIteration
                else:
                    current = self.data[self.iter_ind]
                    self.iter_ind+=1
            finally:
                if self.ignore_case and current not in self.data: self.data.add(item)
                elif not self.ignore_case and item.lower() not in set(map(str.lower,self.data)): self.data.add(item)


    def __iter__(self):
        return self


if __name__ == "__main__":
    b = ['a', 'A', 'b', 'B', 'a', 'A', 'b', 'B']
    alist = ['Python', 'Java', 'C', 'C++', 'CSharp']
    
    print(Unique(gen_random(5,1,100), ignore_case=True).data)