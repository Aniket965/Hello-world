#!/usr/bin/env python3

import sys
try:
    from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
    import telegram
except ImportError:
    print("Library python-telegram-bot not installed")
    print("pip3 install -r requirements.txt")
    sys.exit(1)
import logging

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO)

logger = logging.getLogger(__name__)

def start(bot, update):
    bot.send_chat_action(chat_id=update.message.chat_id, action=telegram.ChatAction.TYPING)
    update.message.reply_text('Hi! this simple telegram chat bot using python')

def echo(bot, update):
    bot.send_chat_action(chat_id=update.message.chat_id, action=telegram.ChatAction.TYPING)
    update.message.reply_text(update.message.text)

def main():
    updater = Updater('REDACTED BOT API')

    BOT = updater.dispatcher

    BOT.add_handler(CommandHandler("start", start))

    BOT.add_handler(MessageHandler(Filters.text, echo))

    updater.start_polling()

    updater.idle()
    
if __name__ == '__main__':
    main()
