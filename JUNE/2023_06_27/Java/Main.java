import java.util.*;

public class Main {
    public static void main(String[] args) {
        double pr[] = {49.9, 29.9, 39.9, 59.99};
        String wired = "Wired";
        String wireless = "Wireless";
        String[] wireType = {"Type-B", "Type-C", "Laptop", "iOS"};
        String[] adaptor = {"Android", "Laptop", "Iphone"};
        String[] chargerColor = {"Yellow", "Black", "White"};

        WiredCharger wc = new WiredCharger();
        WirelessCharger wlc = new WirelessCharger();

        wc.setNames(wireType[0], adaptor[0], chargerColor[0], pr[0]);
        wc.checkPowerSupply(wired, wireType[0], adaptor[0]);
        wc.getNames();

        wlc.checkPowerSupply(wireless, wireType[0], adaptor[0]);
        wlc.setNames(wireType[1],adaptor[1], chargerColor[2], pr[1]);
        wlc.getNames();
    }
}

class Charger 
{
    public double maxPowerSupply = 0;
    public double price;
    public String chargerType, chargerColor;
    public String wireType, adaptor;
    
    public void setNames(String wireType, String adaptor, String chargerColor, double price) 
    {
        this.wireType = wireType;
        this.adaptor = adaptor;
        this.chargerColor = chargerColor;
        this.price = price;
    }
    
    public void getNames() 
    {
        System.out.println("\nCharger Type: " + chargerType);
        System.out.println("Wire Type: " + wireType);
        System.out.println("Adaptor Type: " + adaptor);
        System.out.println("Max Power Supply: " + maxPowerSupply);
        System.out.println("Charger Color: " + chargerColor);
        System.out.println("Price: " + price);
    }
}

class WiredCharger extends Charger 
{
    public void checkPowerSupply(String chargerType, String wireType, String adaptor) 
    {
        if (chargerType.equals("Wired")) 
        {
            this.chargerType = "Wired";
            if (wireType.equals("Type-B") && adaptor.equals("Android"))
                maxPowerSupply = 22.5;
            else if (wireType.equals("Type-C") && adaptor.equals("Laptop"))
                maxPowerSupply = 60;
            else if (wireType.equals("Laptop") && adaptor.equals("Laptop"))
                maxPowerSupply = 135;
            else
                maxPowerSupply = 18;
        } 
        else 
        {
            this.chargerType = "Wireless";
            //System.out.println("Charger Type: " + chargerType);
            maxPowerSupply = 10;
        }
    }
}

class WirelessCharger extends Charger 
{
    public void checkPowerSupply(String chargerType, String wireType, String adaptor) 
    {
        if (chargerType.equals("Wired")) 
        {
            this.chargerType = "Wired";
            if (wireType.equals("Type-B") && adaptor.equals("Android"))
                maxPowerSupply = 22;
            else if (wireType.equals("Type-C") && adaptor.equals("Laptop"))
                maxPowerSupply = 60;
            else if (wireType.equals("Laptop") && adaptor.equals("Laptop"))
                maxPowerSupply = 135;
            else
                maxPowerSupply = 18;
        } 
        else 
        {
            this.chargerType = "Wireless";
            // System.out.println("Charger Type: " + chargerType);
            maxPowerSupply = 10.5;
        }
    }
}


