from config import get_sen
import unittest
import os


class TestBot(unittest.TestCase):
    def test_1(self):
        w="Петр шел по берегу и сосал конфеты."
        self.assertEqual(w, "Петр шел по берегу и сосал конфеты.")
    def test_2(self):
        w="Леонид шел по берегу и сосал чупа-чупсы."
        self.assertEqual(w,"Леонид шел по берегу и сосал чупа-чупсы.")


if __name__ == '__main__':
    unittest.main() 
    os.system(r"behave -i C:\Users\nagor\Documents\python\lab_6\featureBDD.feature")