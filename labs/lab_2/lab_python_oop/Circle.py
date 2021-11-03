from lab_python_oop.Figure import Figure
from lab_python_oop.FigureColor import FigureColor
from math import pi

class Circle(Figure):
  name = "Circle"
  radius = float()
  color = FigureColor(0, 0, 0)

  def __init__(self, radius, color):
      self.radius = radius
      self.color = color

  def Square(self):
      return pi * self.radius**2

  def Repr(self):
        res = self.name + ":"
        res += " radius = {};".format(self.radius)
        res += " color = {}.{}.{};".format(self.color.r, self.color.g, self.color.b)
        res += " square = {};".format(self.Square())
        print(res)