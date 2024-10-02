/**
 * Represents a monkey with specific attributes, extending the RescueAnimal class.
 */
public class Monkey extends RescueAnimal {
    // Instance variables specific to monkeys
    private String species; // The species of the monkey (e.g., Capuchin, Macaque)
    private String height; // The height of the monkey (in inches)
    private String tailLength; // The length of the monkey's tail (in inches)
    private String bodyLength; // The length of the monkey's body (in inches)

    // Constant array of valid monkey species
    // This array is public so it can be accessed from other classes.
    // It is final because the valid species should not change.
    // It is static because it belongs to the class itself, not to any specific instance of the class.
    public final static String[] VALID_SPECIES = {
        "Capuchin",
        "Guenon",
        "Macaque",
        "Marmoset",
        "Squirrel monkey",
        "Tamarin"
    };

    /**
     * Constructor for creating a Monkey object with initial values.
     *
     * @param name              The name of the monkey.
     * @param species           The species of the monkey.
     * @param gender            The gender of the monkey.
     * @param age               The age of the monkey.
     * @param weight            The weight of the monkey.
     * @param height            The height of the monkey (in inches).
     * @param bodyLength        The body length of the monkey (in inches).
     * @param tailLength        The tail length of the monkey (in inches).
     * @param acquisitionDate   The date the monkey was acquired.
     * @param acquisitionCountry The country where the monkey was acquired.
     * @param trainingStatus    The training status of the monkey.
     * @param reserved          Whether the monkey is reserved.
     * @param inServiceCountry  The country where the monkey is in service.
     */
    public Monkey(String name, String species, String gender, String age,
                  String weight, String height, String bodyLength, String tailLength,
                  String acquisitionDate, String acquisitionCountry,
                  String trainingStatus, boolean reserved, String inServiceCountry) {
        // Call the constructor of the superclass (RescueAnimal) to initialize inherited attributes
        super(name, "Monkey", gender, age, Double.parseDouble(weight), acquisitionDate, 
              acquisitionCountry, trainingStatus, reserved, inServiceCountry);
        
        // Initialize monkey-specific attributes
        this.species = species;
        this.height = height;
        this.tailLength = tailLength;
        this.bodyLength = bodyLength;
    }

    // Accessor methods (getters) for the monkey's attributes

    /**
     * Gets the species of the monkey.
     * @return The species of the monkey.
     */
    public String getSpecies() {
        return species;
    }

    /**
     * Gets the height of the monkey.
     * @return The height of the monkey.
     */
    public String getHeight() {
        return height;
    }

    /**
     * Gets the tail length of the monkey.
     * @return The tail length of the monkey.
     */
    public String getTailLength() {
        return tailLength;
    }

    /**
     * Gets the body length of the monkey.
     * @return The body length of the monkey.
     */
    public String getBodyLength() {
        return bodyLength;
    }

    // Mutator methods (setters) for the monkey's attributes

    /**
     * Sets the species of the monkey.
     * @param monkeySpecies The new species of the monkey.
     */
    public void setSpecies(String monkeySpecies) {
        species = monkeySpecies;
    }

    /**
     * Sets the height of the monkey.
     * @param monkeyHeight The new height of the monkey.
     */
    public void setHeight(String monkeyHeight) {
        height = monkeyHeight;
    }

    /**
     * Sets the tail length of the monkey.
     * @param monkeyTailLength The new tail length of the monkey.
     */
    public void setTailLength(String monkeyTailLength) {
        tailLength = monkeyTailLength;
    }

    /**
     * Sets the body length of the monkey.
     * @param monkeyBodyLength The new body length of the monkey.
     */
    public void setBodyLength(String monkeyBodyLength) {
        bodyLength = monkeyBodyLength;
    }
}
