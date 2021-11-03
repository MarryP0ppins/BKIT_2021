from lab_python_oop.Rectangle import Rectangle

class Square(Rectangle):
    name = "Square"

    def __init__(self, width, color):
        self.width = width
        self.height = width
        self.color = color

    def square(self):
        return self.height * self.width

    def Repr(self):
        res = self.name + ":"
        res += " side = {};".format(self.width)
        res += " color = {}.{}.{};".format(self.color.r, self.color.g, self.color.b)
        res += " square = {};".format(self.square())
        print(res)


