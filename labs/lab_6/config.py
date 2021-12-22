from enum import Enum

# Токент бота
TOKEN = "5056756185:AAFSbyjc0pwDz8W9WnvyXpsnJoH4LjIT47I"

# Файл базы данных Vedis
db_file = "db.vdb"

# Ключ записи в БД для текущего состояния
CURRENT_STATE = "CURRENT_STATE"

SENTENCE = "SENTENCE"

# Состояния автомата
class States(Enum):
    STATE_START = "STATE_START"  # Начало нового диалога
    STATE_FIRST_WORD = "STATE_FIRST_WORD"
    STATE_SECOND_WORD = "STATE_SECOND_WORD"
    STATE_THIRD_WORD = "STATE_THIRD_WORD"
    STATE_FOURTH_WORD = "STATE_FOURTH_WORD"
    STATE_OPERATION = "STATE_OPERATION"
    STATE_SENTENCE = "STATE_SENTENCE"



def get_sen(lst):
    out = []
    for w in lst.split():
        out.append(w)
    return ' '.join(out)