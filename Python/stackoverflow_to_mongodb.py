
import stackapi
import requests
import pymongo
import traceback
import random

# Settings
TAG = "java"
MAX_ERRORS = 3  # max. consecutive errors before stopping getting questions
PAGE_RANGE = [1, 100]  # range of pages to get questions from (both ranges included)
PAGE_SIZE = 100  # items per page, maximum of 100 (recommended)
MONGODB_SERVER = "localhost:27017"
DB_NAME = "stackoverflow"
COLLECTION_NAME = "java"
PROXIES = ["localhost:9051", "localhost:9052", "localhost:9053", None]

# MongoDB
mongo = pymongo.MongoClient("mongodb://"+MONGODB_SERVER)
db = mongo[DB_NAME]
collection = db[COLLECTION_NAME]

# StackAPI
stack = stackapi.StackAPI("stackoverflow")
stack.page_size = PAGE_SIZE
stack.max_pages = 1
min_page = min(PAGE_RANGE)
max_page = max(PAGE_RANGE)
errors = 0

for page in range(min_page, max_page+1):
    stop = False
    while True:
        try:
            print(f"Getting questions from page {page}/{max_page}")
            proxy = random.choice(PROXIES)
            if proxy is not None:
                proxies = {"http": "http://"+proxy, "https": "https://"+proxy}
            else:
                proxies = None
            js = stack.fetch("questions", tagged=TAG, page=page, is_answered=True, proxy=proxies)
            questions = js["items"]
            print(f"Found {len(questions)} questions")
            for quest in questions:  # type: dict
                print(f"Processing question {questions.index(quest)+1}/{len(questions)} '{quest['title']}'...")
                if not quest["is_answered"]:
                    print("Question not answered, skipping")
                    continue
                if collection.find({"_id": quest["question_id"]}).count() == 1:
                    print("Question already exists in DB, skipping")
                    continue
                tries = 0
                ok = False
                while True:
                    try:
                        proxy = random.choice(PROXIES)
                        if proxy is not None:
                            proxies = {"http": "http://"+proxy, "https": "https://"+proxy}
                        else:
                            proxies = None
                        r = requests.get(quest["link"], timeout=2, proxies=proxies)
                        if r.status_code != 200:
                            raise requests.exceptions.RequestException(f"Error Code != 200 (got {r.status_code})")
                    except requests.exceptions.RequestException as e:
                        try:
                            traceback.print_tb(e)
                        except AttributeError:
                            print(str(e))
                            pass
                        if tries >= MAX_ERRORS:
                            print("Error limit reached, we can't download this question!")
                            break
                        else:
                            tries += 1
                            print("Trying again")
                    else:
                        ok = True
                        break
                # Set ID
                quest["_id"] = quest.pop("question_id")
                # Remove unneeded elements from quest dict
                remove_keys = ["user_type", "profile_image", "link"]
                for k in remove_keys:
                    try:
                        quest["owner"].pop(k)
                    except KeyError:
                        pass
                if ok:
                    quest["html"] = r.text
                else:
                    quest["html"] = None
                collection.insert_one(quest)
                print("Saved!")
        except KeyboardInterrupt:
            print("Manually stopped getting questions")
            stop = True
            break
        except (stackapi.StackAPIError, pymongo.mongo_client.PyMongoError) as e:
            try:
                traceback.print_tb(e)
            except AttributeError:
                print(str(e))
            errors += 1
            if errors >= MAX_ERRORS:
                print("Error limit reached, we stop getting questions!")
                stop = True
                break
            else:
                print("Trying again")
        else:
            errors = 0
            print(f"Retrieved questions from page {page}/{max_page}\n")
            break
    if stop:
        print("Bye!")
        break
