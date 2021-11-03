from lab_python_oop.FigureColor import FigureColor
from lab_python_oop.Rectangle import Rectangle
from lab_python_oop.Square import Square
from lab_python_oop.Circle import Circle
import pygame

def main():
    pygame.init()
    rectangle = Rectangle(5, 5, FigureColor(0, 0, 255))
    square = Square(5, FigureColor(0, 255, 0))
    circle = Circle(5, FigureColor(255, 0, 0))
    print()
    square.Repr()
    rectangle.Repr()
    circle.Repr()
    print()

if __name__ == "__main__":
    main()
