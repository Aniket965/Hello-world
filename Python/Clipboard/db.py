from datetime import datetime
from peewee import SqliteDatabase, CharField, DateTimeField, Model

db = SqliteDatabase("clipboard.db")


class Paste(Model):
    text = CharField()
    date = DateTimeField()

    class Meta:
        database = db


db.create_tables([Paste])


def save_new_paste(text):
    paste = Paste(text=text, date=datetime.now())
    paste.save()


def get_lastest_paste():
    for paste in Paste.select().order_by(Paste.date.desc()):
        return paste.text


def get_pastes():
    return Paste.select().order_by(Paste.date.desc())


def delete_all():
    Paste.delete().execute()
