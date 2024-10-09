from animal_shelter import AnimalShelter
from bson.objectid import ObjectId

# Instantiate the AnimalShelter class, passing in the username and password for the database
animals = AnimalShelter("aacuser", "aacuser")

# =======================================
# CREATE OPERATIONS
# =======================================

# Define a dictionary containing valid animal data to be inserted into the database
valid_animal_data = {
    'age_upon_outcome': "1 years",
    'animal_id': "test",
    'animal_type': "Cat",
    'breed': "Domestic Shorthair Mix",
    'color': "Black & White Tabby",
    'date_of_birth': "2022-03-27",
    'datetime': "2022-03-27 11:14:00",
    'monthyear': "2022-03-27T11:14:00",
    'name': "Binx",
    'outcome_subtype': "",
    'outcome_type': 'Adoption',
    'sex_upon_outcome': "Spayed Male",
    'location_lat': 30.6525984560228,
    'location_long': -97.7419963476444,
    'age_upon_outcome_in_weeks': 52.9215277777778
}

# Attempt to create a new animal document in the database using the valid data
create_result = animals.create(valid_animal_data)

# Print the result of the create operation to the console
print(f"Create Result (Valid Data): {create_result}")

# Invalid Document (Commented out to avoid errors)
# This line is commented out to prevent errors, as it attempts to create a document with an invalid format
# print(animals.create({0:0})) 

# =======================================
# READ OPERATIONS
# =======================================

# Define a valid query to search for animals named "Binx"
valid_query = {"name": "Binx"}

# Execute the read operation using the valid query and store the results in the 'found_animals' variable
found_animals = animals.read(valid_query)

# Print a header for the results of the valid query
print("\nResults for Valid Query:")

# Iterate over the found animals and print each animal's data to the console
for animal in found_animals:
    print(animal)

# Invalid query (Commented out to avoid errors)
# This line is commented out to prevent errors, as it attempts to execute a read operation with an invalid query format
# print(list(animals.read({0:0})))

# =======================================
# UPDATE OPERATIONS
# =======================================

# Define the criteria for updating animal documents (animals named "Binx")
update_criteria = {"name": "Binx"}

# Define the update data to be applied to matching documents (set the 'outcome_type' to "Foster")
update_data = {"$set": {"outcome_type": "Foster"}}

# Execute the update operation using the specified criteria and update data, storing the number of updated documents
updated_count = animals.update(update_criteria, update_data)

# Print the number of documents that were updated to the console
print(f"\nNumber of documents updated: {updated_count}")

# =======================================
# DELETE OPERATIONS
# =======================================

# Define the criteria for deleting animal documents (animals named "Binx")
delete_criteria = {"name": "Binx"}

# Execute the delete operation using the specified criteria, storing the number of deleted documents
deleted_count = animals.delete(delete_criteria)

# Print the number of documents that were deleted to the console
print(f"\nNumber of documents deleted: {deleted_count}")
