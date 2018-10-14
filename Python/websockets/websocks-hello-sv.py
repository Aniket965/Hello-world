import asyncio
import websockets
import sys

async def echo (websocket, path):
    print(websocket)

    async for message in websocket:
        await websocket.send(message)

asyncio.get_event_loop().run_until_complete(websockets.serve(echo, 'localhost', 8765))
asyncio.get_event_loop().run_forever()