import java.util.ArrayList;
import java.util.Scanner;

/**
 * Driver class for the Rescue Animal System.
 * Manages the intake, reservation, and printing of dog and monkey objects.
 */
public class Driver {
    // Instance variables to store lists of dogs and monkeys
    private static ArrayList<Dog> dogList = new ArrayList<>();
    private static ArrayList<Monkey> monkeyList = new ArrayList<>();

    /**
     * Main method for the Rescue Animal System.
     * Initializes animal lists, displays the menu, and handles user input.
     *
     * @param args Command line arguments (not used).
     */
    public static void main(String[] args) {
        // Initialize the lists of dogs and monkeys
        initializeDogList();
        initializeMonkeyList();

        // Controls the menu loop
        boolean acceptingInput = true;
        Scanner input = new Scanner(System.in);

        // Main menu loop
        while (acceptingInput) {
            // Display the menu options to the user
            displayMenu();

            // Get the user's menu selection
            String option = input.nextLine().trim().toLowerCase();

            // Process user input
            switch (option) {
                case "1":
                    // Intake a new dog
                    intakeNewDog(input);
                    break;
                case "2":
                    // Intake a new monkey
                    intakeNewMonkey(input);
                    break;
                case "3":
                    // Reserve an animal
                    reserveAnimal(input);
                    break;
                case "4":
                    // Print all dogs
                    printAnimals("dog");
                    break;
                case "5":
                    // Print all monkeys
                    printAnimals("monkey");
                    break;
                case "6":
                    // Print all available animals
                    printAnimals("available");
                    break;
                case "q":
                    // Quit the application
                    acceptingInput = false;
                    break;
                default:
                    // Handle invalid input
                    System.out.println("Invalid option, please input a valid option");
                    break;
            }
        }

        // Print a goodbye message when the loop exits
        System.out.println("Goodbye");
    }

    /**
     * Displays the main menu options to the user.
     */
    public static void displayMenu() {
        System.out.println("\n\n");
        System.out.println("\t\t\t\tRescue Animal System Menu");
        System.out.println("[1] Intake a new dog");
        System.out.println("[2] Intake a new monkey");
        System.out.println("[3] Reserve an animal");
        System.out.println("[4] Print a list of all dogs");
        System.out.println("[5] Print a list of all monkeys");
        System.out.println("[6] Print a list of all animals that are not reserved");
        System.out.println("[q] Quit application");
        System.out.println();
        System.out.println("Enter a menu selection");
    }

    /**
     * Initializes the dog list with some sample dog objects.
     */
    public static void initializeDogList() {
        Dog dog1 = new Dog("Spot", "German Shepherd", "male", "1", "25.6", "05-12-2019", "United States", "intake", false, "United States");
        Dog dog2 = new Dog("Rex", "Great Dane", "male", "3", "35.2", "02-03-2020", "United States", "Phase I", false, "United States");
        Dog dog3 = new Dog("Bella", "Chihuahua", "female", "4", "25.6", "12-12-2019", "Canada", "in service", true, "Canada");

        dogList.add(dog1);
        dogList.add(dog2);
        dogList.add(dog3);
    }

    /**
     * Initializes the monkey list with some sample monkey objects.
     */
    public static void initializeMonkeyList() {
        Monkey monkey1 = new Monkey("Cappy", "Capuchin", "male", "1", "5.6", "15", "10", "5", "05-21-2021", "United States", "intake", false, "United States");
        Monkey monkey2 = new Monkey("Max", "Macaque", "male", "3", "15.2", "63", "53", "10", "02-29-2002", "United States", "Phase I", false, "United States");
        Monkey monkey3 = new Monkey("Tammy", "Tamarin", "female", "4", "1.6", "9", "1", "0.6", "12-21-2012", "Canada", "in service", false, "Canada");

        monkeyList.add(monkey1);
        monkeyList.add(monkey2);
        monkeyList.add(monkey3);
    }

    /**
     * Prompts the user for information about a new dog and adds it to the dog list.
     *
     * @param scanner The Scanner object to use for user input.
     */
    public static void intakeNewDog(Scanner scanner) {
        System.out.println("What is the dog's name?");
        String name = scanner.nextLine().trim();

        // Check for duplicate dog names
        if (isDuplicateAnimalName(dogList, name)) {
            System.out.println("\n\nThis dog is already in our system\n\n");
            return;
        }

        // Gather information about the new dog
        System.out.println("What is " + name + "'s breed?");
        String breed = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s gender? (\"male\", \"female\")");
        String gender = scanner.nextLine().trim().toLowerCase();

        System.out.println("What is " + name + "'s age?");
        String age = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s weight? (in pounds)");
        String weight = scanner.nextLine().trim();

        System.out.println("When was " + name + " acquired? (MM-DD-YYYY)");
        String acquisitionDate = scanner.nextLine().trim();

        System.out.println("Where was " + name + " acquired? (Country)");
        String acquisitionCountry = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s training status? (\"intake\", \"in service\", \"phase I/II/III/IV/V\", \"farm\")");
        String trainingStatus = scanner.nextLine().trim();

        System.out.println("Is " + name + " reserved? (Y/N)");
        boolean reserved = scanner.nextLine().trim().equalsIgnoreCase("Y");

        System.out.println("What is " + name + "'s service country?");
        String inServiceCountry = scanner.nextLine().trim();

        // Create a new Dog object and add it to the dog list
        Dog newDog = new Dog(name, breed, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
        dogList.add(newDog);
    }

    /**
     * Prompts the user for information about a new monkey and adds it to the monkey list.
     *
     * @param scanner The Scanner object to use for user input.
     */
    public static void intakeNewMonkey(Scanner scanner) {
        System.out.println("What is the monkey's name?");
        String name = scanner.nextLine().trim();

        // Check for duplicate monkey names
        if (isDuplicateAnimalName(monkeyList, name)) {
            System.out.println("\n\nThis monkey is already in our system\n\n");
            return;
        }

        // Validate and gather the monkey's species
        String species;
        do {
            System.out.println("What is " + name + "'s species?");
            species = scanner.nextLine().trim();

            if (!isValidMonkeySpecies(species)) {
                System.out.println("Invalid species option. Valid options are:");
                for (String validSpecies : Monkey.VALID_SPECIES) {
                    System.out.println("- " + validSpecies);
                }
            }
        } while (!isValidMonkeySpecies(species));

        // Gather remaining information about the new monkey
        System.out.println("What is " + name + "'s gender? (\"male\", \"female\")");
        String gender = scanner.nextLine().trim().toLowerCase();

        System.out.println("What is " + name + "'s age?");
        String age = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s weight? (in pounds)");
        String weight = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s height? (head to toe; in inches)");
        String height = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s body length? (head to pelvis; in inches)");
        String bodyLength = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s tail length? (base to tip; in inches)");
        String tailLength = scanner.nextLine().trim();

        System.out.println("When was " + name + " acquired? (MM-DD-YYYY)");
        String acquisitionDate = scanner.nextLine().trim();

        System.out.println("Where was " + name + " acquired? (Country)");
        String acquisitionCountry = scanner.nextLine().trim();

        System.out.println("What is " + name + "'s training status? (\"intake\", \"in service\", \"phase I/II/III/IV/V\", \"farm\")");
        String trainingStatus = scanner.nextLine().trim();

        System.out.println("Is " + name + " reserved? (Y/N)");
        boolean reserved = scanner.nextLine().trim().equalsIgnoreCase("Y");

        System.out.println("What is " + name + "'s service country?");
        String inServiceCountry = scanner.nextLine().trim();

        // Create a new Monkey object and add it to the monkey list
        Monkey newMonkey = new Monkey(name, species, gender, age, weight, height, bodyLength, tailLength, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
        monkeyList.add(newMonkey);
    }

    /**
     * Attempts to reserve an animal of the specified type and service country.
     * The first available (not reserved and in service) animal of the specified type
     * in the specified country will be reserved.
     *
     * @param scanner The Scanner object to use for user input.
     */
    public static void reserveAnimal(Scanner scanner) {
        System.out.println("What type of animal will be needed? (\"dog\", \"monkey\")");
        String animalType = scanner.nextLine().trim();

        System.out.println("Where will the animal be serving? (Country)");
        String animalServiceCountry = scanner.nextLine().trim();

        if (animalType.equalsIgnoreCase("dog")) {
            // Attempt to reserve a dog
            if (reserveDog(animalServiceCountry)) {
                return;
            }
        } else if (animalType.equalsIgnoreCase("monkey")) {
            // Attempt to reserve a monkey
            if (reserveMonkey(animalServiceCountry)) {
                return;
            }
        }

        // If no animal could be reserved, print a message to the user
        System.out.println("Unable to reserve a " + animalType + " from " + animalServiceCountry + " at this time");
    }

    /**
     * Attempts to reserve the first available dog in the specified service country.
     *
     * @param serviceCountry The service country for the dog.
     * @return True if a dog was reserved, false otherwise.
     */
    private static boolean reserveDog(String serviceCountry) {
        // Iterate through the list of dogs
        for (Dog dog : dogList) {
            // Check if the dog is not reserved, is in the specified service country, and is in service
            if (!dog.getReserved() && dog.getInServiceLocation().equalsIgnoreCase(serviceCountry) && dog.getTrainingStatus().equalsIgnoreCase("in service")) {
                // If all conditions are met, reserve the dog
                dog.setReserved(true);
                System.out.println(dog.getName() + " has been reserved");
                return true;
            }
        }

        // If no dog was reserved, return false
        return false;
    }

    /**
     * Attempts to reserve the first available monkey in the specified service country.
     *
     * @param serviceCountry The service country for the monkey.
     * @return True if a monkey was reserved, false otherwise.
     */
    private static boolean reserveMonkey(String serviceCountry) {
        // Iterate through the list of monkeys
        for (Monkey monkey : monkeyList) {
            // Check if the monkey is not reserved, is in the specified service country, and is in service
            if (!monkey.getReserved() && monkey.getInServiceLocation().equalsIgnoreCase(serviceCountry) && monkey.getTrainingStatus().equalsIgnoreCase("in service")) {
                // If all conditions are met, reserve the monkey
                monkey.setReserved(true);
                System.out.println(monkey.getName() + " has been reserved");
                return true;
            }
        }

        // If no monkey was reserved, return false
        return false;
    }

    /**
     * Prints a list of animals based on the specified output type.
     *
     * @param outputType The type of animals to print ("dog", "monkey", or "available").
     */
    public static void printAnimals(String outputType) {
        // Print header
        System.out.printf("%-8.15s\t| %-1.15s\t| %-1.15s\t| %s%n%n", "Name", "Status", "Acq. Country", "Reserved");

        switch (outputType.toLowerCase()) {
            case "dog":
                // Print the list of dogs
                printDogList();
                break;
            case "monkey":
                // Print the list of monkeys
                printMonkeyList();
                break;
            case "available":
                // Print the list of available animals
                printAvailableAnimals();
                break;
            default:
                // Handle invalid output type
                System.out.println("Invalid output type.");
        }
    }

    /**
     * Prints information for each dog in the dog list.
     */
    private static void printDogList() {
        // Iterate through the list of dogs and print their information
        for (Dog dog : dogList) {
            System.out.printf("%-8.15s\t| %-1.15s\t| %-1.15s\t| %s%n",
                    dog.getName(), dog.getTrainingStatus(), dog.getAcquisitionLocation(), dog.getReserved());
        }
    }

    /**
     * Prints information for each monkey in the monkey list.
     */
    private static void printMonkeyList() {
        // Iterate through the list of monkeys and print their information
        for (Monkey monkey : monkeyList) {
            System.out.printf("%-8.15s\t| %-1.15s\t| %-1.15s\t| %s%n",
                    monkey.getName(), monkey.getTrainingStatus(), monkey.getAcquisitionLocation(), monkey.getReserved());
        }
    }

    /**
     * Prints information for all available animals (not reserved and in service).
     */
    private static void printAvailableAnimals() {
        // Iterate through the list of dogs
        for (Dog dog : dogList) {
            // Check if the dog is not reserved and is in service
            if (!dog.getReserved() && dog.getTrainingStatus().equalsIgnoreCase("in service")) {
                // If both conditions are met, print the dog's information
                System.out.printf("%-8.15s\t| %-1.15s\t| %-1.15s\t| %s%n",
                        dog.getName(), dog.getTrainingStatus(), dog.getAcquisitionLocation(), dog.getReserved());
            }
        }

        // Iterate through the list of monkeys
        for (Monkey monkey : monkeyList) {
            // Check if the monkey is not reserved and is in service
            if (!monkey.getReserved() && monkey.getTrainingStatus().equalsIgnoreCase("in service")) {
                // If both conditions are met, print the monkey's information
                System.out.printf("%-8.15s\t| %-1.15s\t| %-1.15s\t| %s%n",
                        monkey.getName(), monkey.getTrainingStatus(), monkey.getAcquisitionLocation(), monkey.getReserved());
            }
        }
    }

    /**
     * Checks if an animal with the given name already exists in the specified list.
     *
     * @param animalList The list of animals to check.
     * @param name       The name to search for.
     * @return True if a duplicate name is found, false otherwise.
     */
    private static boolean isDuplicateAnimalName(ArrayList<? extends RescueAnimal> animalList, String name) {
        // Iterate through the list of animals
        for (RescueAnimal animal : animalList) {
            // Check if the animal's name matches the given name (case-insensitive)
            if (animal.getName().equalsIgnoreCase(name)) {
                return true;
            }
