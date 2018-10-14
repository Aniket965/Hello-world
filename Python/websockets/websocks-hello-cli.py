import asyncio
import websockets
import sys


async def hello_world(uri):
    async with websockets.connect(uri) as websocket:
        await websocket.send("Hello World!")

        response = await websocket.recv()
        print(response)

asyncio.get_event_loop().run_until_complete(hello_world('ws://localhost:8765'))
