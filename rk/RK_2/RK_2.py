
# используется для сортировки
from operator import itemgetter
 
class Comp:
    def __init__(self, id, fio, sal, disp_class_id):
        self.id = id
        self.fio = fio
        self.sal = sal
        self.disp_class_id = disp_class_id
 
class Disp_class:
    def __init__(self, id, name):
        self.id = id
        self.name = name
 
class CompDisp_class:
    def __init__(self, disp_class_id, comp_id):
        self.disp_class_id = disp_class_id
        self.comp_id = comp_id

disp_classs = [Disp_class(1, 'А-класс'),
    Disp_class(2, 'Б-класс'),
    Disp_class(3, 'В-класс'),
 
    Disp_class(11, 'Г-класс'),
    Disp_class(22, 'Д-класс'),
    Disp_class(33, 'Е-класс'),]
 
comps = [Comp(1, 'Asus', 134200, 2),
    Comp(2, 'HP', 87123, 3),
    Comp(3, 'Dell', 204500, 2),
    Comp(4, 'ThinkPad', 64990, 1),
    Comp(5, 'Acer', 109990, 3),]
 
comps_disp_classs = [CompDisp_class(1,1),
    CompDisp_class(3,2),
    CompDisp_class(3,3),
    CompDisp_class(2,4),
    CompDisp_class(1,5),
 
    CompDisp_class(33,1),
    CompDisp_class(33,2),
    CompDisp_class(11,3),
    CompDisp_class(11,4),
    CompDisp_class(22,5),]
 

def part_1(one_to_many):
    res_11 = [(o.name,list(fio for fio,_,name in one_to_many if name == o.name)) for o in disp_classs if o.name[0] == 'А']
    return res_11


def part_2(one_to_many):
    res_12_unsorted = []
    # Перебираем все дисплейные классы
    for o in disp_classs:
        # Список компьютеров дисплейного класса
        o_comps = list(filter(lambda x: x[2] == o.name, one_to_many))
        # Если дисплейный класс не пустой
        if len(o_comps) > 0:
            res_12_unsorted.append((o.name, max(o_comps, key=lambda x: x[1])[1]))
 
    # Сортировка по максимальной стоимости
    res_12 = sorted(res_12_unsorted, key=itemgetter(1), reverse=True)
    return res_12



def part_3(many_to_many):
    res_13 = []
    # Перебираем все дисплейные классы
    for comp,_,disp_class in many_to_many:
        res_13.append((comp, disp_class))
    res_13 = sorted(res_13, key=itemgetter(1))
    return res_13



def main():
    one_to_many = [(m.fio, m.sal, o.name) 
        for o in disp_classs 
        for m in comps 
        if m.disp_class_id == o.id]
    
    many_to_many_temp = [(o.name, mo.disp_class_id, mo.comp_id) 
        for o in disp_classs 
        for mo in comps_disp_classs 
        if o.id == mo.disp_class_id]
    
    many_to_many = [(m.fio, m.sal, disp_class_name) 
        for disp_class_name, disp_class_id, comp_id in many_to_many_temp
        for m in comps if m.id == comp_id]

    print(one_to_many)

    print(many_to_many)
    
    print('Задание Г1')
    print(part_1(one_to_many))
    print('\nЗадание Г2')
    print(part_2(one_to_many))
    print('\nЗадание Г3')
    print(part_3(many_to_many))
 
if __name__ == '__main__':
    main()
