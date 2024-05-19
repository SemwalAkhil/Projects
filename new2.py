# import logging
# from telegram.ext import Updater, CommandHandler, MessageHandler, filters
# import openai

# # Enable logging
# logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
#                     level=logging.INFO)
# logger = logging.getLogger(__name__)

# # Define your API keys
# TELEGRAM_API_KEY = '7128721612:AAHScAeN4hdGkSQ5unbXmWC-pJJM_AWNbYs'
# OPENAI_API_KEY = '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'

# # Initialize OpenAI
# openai.api_key = OPENAI_API_KEY

# def start(update, context):
#     """Send a message when the command /start is issued."""
#     update.message.reply_text('Hi! I am your Telegram bot connected to GPT.')

# def echo(update, context):
#     """Echo the user message."""
#     user_text = update.message.text  # Get the text input from user
#     gpt_response = openai.ChatCompletion.create(
#         model="gpt-3.5-turbo",
#         messages=[{"role": "system", "content": "Your system message here"},
#                   {"role": "user", "content": user_text}]
#     )
#     update.message.reply_text(gpt_response.choices[0].message['content'])

# def error(update, context):
#     """Log Errors caused by Updates."""
#     logger.warning('Update "%s" caused error "%s"', update, context.error)

# def main():
#     """Start the bot."""
#     # Create the Updater and pass it your bot's token.
#     updater = Updater(TELEGRAM_API_KEY, use_context=True)

#     # Get the dispatcher to register handlers
#     dp = updater.dispatcher

#     # on different commands - answer in Telegram
#     #
#     dp.add_handler(CommandHandler("start", start))

#     # on noncommand i.e message - echo the message on Telegram
#     dp.add_handler(MessageHandler(filters.text, echo))

#     # log all errors
#     dp.add_error_handler(error)

#     # Start the Bot
#     updater.start_polling()
#     updater.idle()

# if __name__ == '__main__':
#     main()

s = "aBc"

print(s.lower())