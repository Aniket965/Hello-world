from discord.ext import commands
prefix = "?"
bot = commands.Bot(command_prefix=prefix)


@bot.event
async def on_ready():
    print("Hello, World!")

bot.run(TOKEN)  
