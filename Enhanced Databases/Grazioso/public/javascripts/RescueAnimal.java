import java.lang.String;

/**
 * Represents a rescue animal with various attributes.
 */
public class RescueAnimal {
    // Instance variables to store animal information
    private String name; // The name of the animal
    private String animalType; // The type of animal (e.g., dog, cat, bird)
    private String gender; // The gender of the animal (e.g., male, female)
    private String age; // The age of the animal 
    private double weight; // The weight of the animal in pounds (changed to double for accuracy)
    private String acquisitionDate; // The date the animal was acquired (format: MM-DD-YYYY)
    private String acquisitionCountry; // The country where the animal was acquired
    private String trainingStatus; // The training status of the animal (e.g., intake, in service, phase I, etc.)
    private boolean reserved; // Indicates whether the animal is reserved for adoption
    private String inServiceCountry; // The country where the animal is currently in service

    // Constructor 
    // Creates a new RescueAnimal object with default values.
    public RescueAnimal() {}

    /**
     * Constructor with parameters for creating a RescueAnimal object with initial values.
     * @param name The name of the animal.
     * @param animalType The type of animal.
     * @param gender The gender of the animal.
     * @param age The age of the animal.
     * @param weight The weight of the animal in pounds.
     * @param acquisitionDate The date the animal was acquired.
     * @param acquisitionCountry The country where the animal was acquired.
     * @param trainingStatus The training status of the animal.
     * @param reserved Whether the animal is reserved.
     * @param inServiceCountry The country where the animal is in service.
     */
    public RescueAnimal(String name, String animalType, String gender, String age, 
                        double weight, String acquisitionDate, String acquisitionCountry, 
                        String trainingStatus, boolean reserved, String inServiceCountry) {
        this.name = name;
        this.animalType = animalType;
        this.gender = gender;
        this.age = age;
        this.weight = weight;
        this.acquisitionDate = acquisitionDate;
        this.acquisitionCountry = acquisitionCountry;
        this.trainingStatus = trainingStatus;
        this.reserved = reserved;
        this.inServiceCountry = inServiceCountry;
    }

    // Getters and Setters for each instance variable

    /**
     * Gets the name of the animal.
     * @return The name of the animal.
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the name of the animal.
     * @param name The new name of the animal.
     */
    public void setName(String name) {
        this.name = name;
    }

    // (Similar comments for other getters and setters)
    // ...

    /**
     * Gets the weight of the animal in pounds.
     * @return The weight of the animal.
     */
    public double getWeight() { 
        return weight;
    }

    /**
     * Sets the weight of the animal in pounds.
     * @param weight The new weight of the animal.
     */
    public void setWeight(double weight) { 
        this.weight = weight;
    }

    // ... (Getters and setters for other attributes)

    /**
     * Returns a string representation of the RescueAnimal object.
     * @return A string containing the animal's information.
     */
    @Override
    public String toString() {
        return "Name: " + name + ", Type: " + animalType + ", Gender: " + gender +
               ", Age: " + age + ", Weight: " + weight + ", Acquisition Date: " + 
               acquisitionDate + ", Acquisition Country: " + acquisitionCountry +
               ", Training Status: " + trainingStatus + ", Reserved: " + reserved +
               ", In Service Country: " + inServiceCountry;
    }
}
