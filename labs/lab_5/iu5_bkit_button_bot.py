import os
import telebot
from telebot import types

# Токент бота
TOKEN = '5077740843:AAF9iRRBJWMEf6MS-GWcOr0nATVjeFMTqvo'

# Сообщения
mes_cat = 'вывести котика'
mes_dog = 'вывести собачку'

# Путь к текущему каталогу
cur_path = os.path.dirname(os.path.abspath(__file__))

# Создание бота
bot = telebot.TeleBot(TOKEN)

@bot.message_handler(func=lambda message: True)
def echo_all(message):
	# Идентификатор диалога
	chat_id = message.chat.id

	# Текст, введенный пользователем, то есть текст с кнопки
	text = message.text
	
	# Проверка сообщения и вывод данных
	if text==mes_cat:
		img = open(os.path.join(cur_path, 'img\cat.jpeg'), 'rb')
		bot.send_photo(chat_id, img)
	elif text==mes_dog:
		img = open(os.path.join(cur_path, 'img\dog.jpg'), 'rb')
		bot.send_photo(chat_id, img)
	else:
		markup = types.ReplyKeyboardMarkup(row_width=2, resize_keyboard=True)
		itembtn1 = types.KeyboardButton(mes_cat)
		itembtn2 = types.KeyboardButton(mes_dog)
		markup.add(itembtn1, itembtn2)
		bot.send_message(chat_id, 'Пожалуйста, нажмите кнопку', reply_markup=markup)

bot.infinity_polling()


