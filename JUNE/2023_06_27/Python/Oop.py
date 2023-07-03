class Charger:
    def __init__(self):
        self.maxPowerSupply = 0
        self.price = 0.0
        self.chargerType = ""
        self.chargerColor = ""
        self.wireType = ""
        self.adaptor = ""

    def setNames(self, wireType, adaptor, chargerColor, price):
        self.wireType = wireType
        self.adaptor = adaptor
        self.chargerColor = chargerColor
        self.price = price

    def getNames(self):
        print("\nCharger Type: " + self.chargerType)
        print("Wire Type: " + self.wireType)
        print("Adaptor Type: " + self.adaptor)
        print("Max Power Supply: " + str(self.maxPowerSupply))
        print("Charger Color: " + self.chargerColor)
        print("Price: " + str(self.price))


class WiredCharger(Charger):
    def checkPowerSupply(self, chargerType, wireType, adaptor):
        if chargerType == "Wired":
            self.chargerType = "Wired"
            if wireType == "Type-B" and adaptor == "Android":
                self.maxPowerSupply = 22.5
            elif wireType == "Type-C" and adaptor == "Laptop":
                self.maxPowerSupply = 60
            elif wireType == "Laptop" and adaptor == "Laptop":
                self.maxPowerSupply = 135
            else:
                self.maxPowerSupply = 18
        else:
            self.chargerType = "Wireless"
            self.maxPowerSupply = 10


class WirelessCharger(Charger):
    def checkPowerSupply(self, chargerType, wireType, adaptor):
        if chargerType == "Wired":
            self.chargerType = "Wired"
            if wireType == "Type-B" and adaptor == "Android":
                self.maxPowerSupply = 22
            elif wireType == "Type-C" and adaptor == "Laptop":
                self.maxPowerSupply = 60
            elif wireType == "Laptop" and adaptor == "Laptop":
                self.maxPowerSupply = 135
            else:
                self.maxPowerSupply = 18
        else:
            self.chargerType = "Wireless"
            self.maxPowerSupply = 10.5


if __name__ == "__main__":
    pr = [49.9, 29.9, 39.9, 59.99]
    wired = "Wired"
    wireless = "Wireless"
    wireType = ["Type-B", "Type-C", "Laptop", "iOS"]
    adaptor = ["Android", "Laptop", "Iphone"]
    chargerColor = ["Yellow", "Black", "White"]

    wc = WiredCharger()
    wlc = WirelessCharger()

    wc.setNames(wireType[0], adaptor[0], chargerColor[0], pr[0])
    wc.checkPowerSupply(wired, wireType[0], adaptor[0])
    wc.getNames()

    wlc.checkPowerSupply(wireless, wireType[0], adaptor[0])
    wlc.setNames(wireType[1], adaptor[1], chargerColor[2], pr[1])
    wlc.getNames()

