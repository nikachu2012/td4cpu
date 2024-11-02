// rom data define
bool romData[16][8] = {
    {1, 0, 1, 1, 0, 0, 1, 1}, // address 0
    {1, 0, 1, 1, 0, 1, 1, 0}, // address 1
    {1, 0, 1, 1, 1, 1, 0, 0}, // address 2
    {1, 0, 1, 1, 1, 0, 0, 0}, // address 3

    {1, 0, 1, 1, 1, 0, 0, 0}, // address 4
    {1, 0, 1, 1, 1, 1, 0, 0}, // address 5
    {1, 0, 1, 1, 0, 1, 1, 0}, // address 6
    {1, 0, 1, 1, 0, 0, 1, 1}, // address 7

    {1, 0, 1, 1, 0, 0, 0, 1}, // address 8
    {1, 1, 1, 1, 0, 0, 0, 0}, // address 9
    {0, 0, 0, 0, 0, 0, 0, 0}, // address 10
    {0, 0, 0, 0, 0, 0, 0, 0}, // address 11

    {0, 0, 0, 0, 0, 0, 0, 0}, // address 12
    {0, 0, 0, 0, 0, 0, 0, 0}, // address 13
    {0, 0, 0, 0, 0, 0, 0, 0}, // address 14
    {0, 0, 0, 0, 0, 0, 0, 0}, // address 15
};

void writeDataBus(bool data[])
{
    digitalWrite(D0, data[7]);
    digitalWrite(D1, data[6]);
    digitalWrite(D2, data[5]);
    digitalWrite(D3, data[4]);
    digitalWrite(D4, data[3]);
    digitalWrite(D5, data[2]);
    digitalWrite(D6, data[1]);
    digitalWrite(D7, data[0]);
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

    bool allLow[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
    writeDataBus(allLow);
}

void loop()
{
    uint8_t address = (bool)digitalRead(D8) | ((bool)digitalRead(D9) << 1) | ((bool)digitalRead(D10) << 2) | ((bool)digitalRead(D11) << 3);

    writeDataBus(romData[address]);
}
