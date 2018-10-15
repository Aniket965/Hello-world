'''sleep sort
Sorting algorithm based on sleeping

Takes a list of integers and outputs them in ascending order in max(nums)
seconds
'''
import asyncio
import sys


async def say(n):
    await asyncio.sleep(n)
    print(n)


async def main(nums):
    tasks = [asyncio.create_task(say(n)) for n in nums]
    await asyncio.gather(*tasks)


if __name__ == '__main__':
    nums = [int(n) for n in sys.argv[1:]]
    asyncio.run(main(nums))
