// rom data define
uint8_t rom[] = {0xb3, 0xb6, 0xbc, 0xb8, 0xb8, 0xbc, 0xb6, 0xb3, 0xb1, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void writeDataBus(uint8_t data)
{
    digitalWrite(D0, data & 0b00000001);
    digitalWrite(D1, data & 0b00000010);
    digitalWrite(D2, data & 0b00000100);
    digitalWrite(D3, data & 0b00001000);
    digitalWrite(D4, data & 0b00010000);
    digitalWrite(D5, data & 0b00100000);
    digitalWrite(D6, data & 0b01000000);
    digitalWrite(D7, data & 0b10000000);
}

void setup()
{
    // pin mode define
    pinMode(D8, INPUT);
    pinMode(D9, INPUT);
    pinMode(D10, INPUT);
    pinMode(D11, INPUT);

    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);

    writeDataBus(0x00);
}

void loop()
{
    uint8_t address = (bool)digitalRead(D8) | ((bool)digitalRead(D9) << 1) | ((bool)digitalRead(D10) << 2) | ((bool)digitalRead(D11) << 3);

    writeDataBus(rom[address]);
}
