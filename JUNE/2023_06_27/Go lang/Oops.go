package main

import "fmt"

type Charger struct {
    maxPowerSupply float64
    price          float64
    chargerType    string
    chargerColor   string
    wireType       string
    adaptor        string
}

func (c *Charger) setNames(wireType string, adaptor string, chargerColor string, price float64) {
    c.wireType = wireType
    c.adaptor = adaptor
    c.chargerColor = chargerColor
    c.price = price
}

func (c *Charger) getNames() {
    fmt.Println("\nCharger Type:", c.chargerType)
    fmt.Println("Wire Type:", c.wireType)
    fmt.Println("Adaptor Type:", c.adaptor)
    fmt.Println("Max Power Supply:", c.maxPowerSupply)
    fmt.Println("Charger Color:", c.chargerColor)
    fmt.Println("Price:", c.price)
}

type WiredCharger struct {
    Charger
}

func (wc *WiredCharger) checkPowerSupply(chargerType string, wireType string, adaptor string) {
    if chargerType == "Wired" {
        wc.chargerType = "Wired"
        if wireType == "Type-B" && adaptor == "Android" {
            wc.maxPowerSupply = 22.5
        } else if wireType == "Type-C" && adaptor == "Laptop" {
            wc.maxPowerSupply = 60
        } else if wireType == "Laptop" && adaptor == "Laptop" {
            wc.maxPowerSupply = 135
        } else {
            wc.maxPowerSupply = 18
        }
    } else {
        wc.chargerType = "Wireless"
        wc.maxPowerSupply = 10
    }
}

type WirelessCharger struct {
    Charger
}

func (wlc *WirelessCharger) checkPowerSupply(chargerType string, wireType string, adaptor string) {
    if chargerType == "Wired" {
        wlc.chargerType = "Wired"
        if wireType == "Type-B" && adaptor == "Android" {
            wlc.maxPowerSupply = 22
        } else if wireType == "Type-C" && adaptor == "Laptop" {
            wlc.maxPowerSupply = 60
        } else if wireType == "Laptop" && adaptor == "Laptop" {
            wlc.maxPowerSupply = 135
        } else {
            wlc.maxPowerSupply = 18
        }
    } else {
        wlc.chargerType = "Wireless"
        wlc.maxPowerSupply = 10.5
    }
}

func main() {
    pr := []float64{49.9, 29.9, 39.9, 59.99}
    wired := "Wired"
    wireless := "Wireless"
    wireType := []string{"Type-B", "Type-C", "Laptop", "iOS"}
    adaptor := []string{"Android", "Laptop", "Iphone"}
    chargerColor := []string{"Yellow", "Black", "White"}

    wc := WiredCharger{}
    wlc := WirelessCharger{}

    wc.setNames(wireType[0], adaptor[0], chargerColor[0], pr[0])
    wc.checkPowerSupply(wired, wireType[0], adaptor[0])
    wc.getNames()

    wlc.checkPowerSupply(wireless, wireType[0], adaptor[0])
    wlc.setNames(wireType[1], adaptor[1], chargerColor[2], pr[1])
    wlc.getNames()
}

