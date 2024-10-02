/**
 * Represents a dog with a specific breed, extending the RescueAnimal class.
 * This class inherits attributes from RescueAnimal and adds a breed attribute.
 */
public class Dog extends RescueAnimal {
    // Instance variable specific to dogs
    private String breed;  // The breed of the dog (e.g., Labrador, Golden Retriever)

    /**
     * Constructor for creating a Dog object with initial values.
     * 
     * @param name              The name of the dog.
     * @param breed             The breed of the dog.
     * @param gender            The gender of the dog.
     * @param age               The age of the dog.
     * @param weight            The weight of the dog (as a String, will be parsed to double).
     * @param acquisitionDate   The date the dog was acquired.
     * @param acquisitionCountry The country where the dog was acquired.
     * @param trainingStatus    The training status of the dog.
     * @param reserved          Whether the dog is reserved.
     * @param inServiceCountry  The country where the dog is in service.
     */
    public Dog(String name, String breed, String gender, String age,
               String weight, String acquisitionDate, String acquisitionCountry,
               String trainingStatus, boolean reserved, String inServiceCountry) {
        // Call the constructor of the superclass (RescueAnimal) to initialize inherited attributes
        super(name, "Dog", gender, age, Double.parseDouble(weight), acquisitionDate, 
              acquisitionCountry, trainingStatus, reserved, inServiceCountry);

        // Initialize the dog-specific attribute
        this.breed = breed; 
    }

    /**
     * Gets the breed of the dog.
     * @return The breed of the dog.
     */
    public String getBreed() {
        return breed;
    }

    /**
     * Sets the breed of the dog.
     * @param dogBreed The new breed of the dog.
     */
    public void setBreed(String dogBreed) {
        breed = dogBreed;
    }
}
