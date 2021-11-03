from lab_python_oop.Figure import Figure
from lab_python_oop.FigureColor import FigureColor

class Rectangle(Figure):
    name = "Rectangle"
    width = float()
    height = float()
    color = FigureColor(0, 0, 0)

    def __init__(self, width, height, color):
        self.color = color
        self.width = width
        self.height = height

    def Square(self):
        return self.width * self.height / 2

    def Repr(self):
        res = self.name + ":"
        res += " width = {};".format(self.width)
        res += " height = {};".format(self.height)
        res += " color = {}.{}.{};".format(self.color.r, self.color.g, self.color.b)
        res += " square = {};".format(self.Square())
        print(res)