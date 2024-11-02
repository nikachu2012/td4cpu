# MicroPython
from machine import Pin

program = b"\xb3\xb6\xbc\xb8\xb8\xbc\xb6\xb3\xb1\xf0\x00\x00\x00\x00\x00\x00"

address3 = Pin(2, Pin.IN)
address2 = Pin(3, Pin.IN)
address1 = Pin(4, Pin.IN)
address0 = Pin(5, Pin.IN)

bus7 = Pin(6, Pin.OUT)
bus6 = Pin(7, Pin.OUT)
bus5 = Pin(8, Pin.OUT)
bus4 = Pin(9, Pin.OUT)
bus3 = Pin(10, Pin.OUT)
bus2 = Pin(11, Pin.OUT)
bus1 = Pin(12, Pin.OUT)
bus0 = Pin(13, Pin.OUT)


def writeData(data: int):
    bus7.value(data & 0b10000000)
    bus6.value(data & 0b01000000)
    bus5.value(data & 0b00100000)
    bus4.value(data & 0b00010000)
    bus3.value(data & 0b00001000)
    bus2.value(data & 0b00000100)
    bus1.value(data & 0b00000010)
    bus0.value(data & 0b00000001)


def getAddress() -> int:
    return (address3.value() << 3) | (address2.value() << 2) | (address1.value() << 1) | address0.value()


while True:
    try:
        addr = getAddress()
        writeData(program[addr])
    except Exception:
        continue
