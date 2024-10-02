from pymongo import MongoClient
from bson.objectid import ObjectId
from bson import json_util

class AnimalShelter:
    """
    A class to interact with a MongoDB database for managing animal shelter data.
    This class provides methods for creating, reading, updating, and deleting animal records.
    """

    def __init__(self, username, password):
        """
        Initializes the AnimalShelter object by establishing a connection to the MongoDB database.

        Args:
            username (str): The username for the database connection.
            password (str): The password for the database connection.
        """
        #print('Attempting to connect. . . ')
        try:
            # Establish a connection to the MongoDB server
            self.client = MongoClient('mongodb://%s:%s@nv-desktop-services.apporto.com:31059/test?authSource=AAC' % (username, password))
            
            # Access the specified database
            self.database = self.client.AAC
            
            # Access the specified collection within the database
            self.collection = self.database.animals
            
            #print("Connected successfully!")
        except Exception as e:
            print(f"Could not connect to MongoDB. Error: {e}")

    def create(self, create_input):
        """
        Creates a new document in the database.

        Args:
            create_input (dict): The data for the new document.

        Returns:
            bool: True if the creation was successful, False otherwise.
        """
        print('Attempting to Create. . . ')
        try:
            # Attempt to insert the new document into the collection
            result = self.collection.insert_one(create_input)
            
            # Print the ID of the inserted document
            print(f'Creation successful! Inserted ID: {result.inserted_id}')
            return True
        except Exception as e:
            print(f'Creation failed. Error: {e}')
            return False

    def read_one(self, read_filter):
        """
        Reads and returns a single document matching the filter.

        Args:
            read_filter (dict): The filter to apply to the read operation.

        Returns:
            dict: The matching document (excluding _id) or None if not found.
        """
        print('Attempting to Read (One). . . ')
        try:
            # Attempt to find a single document matching the filter
            result = self.collection.find_one(read_filter, {"_id": False})  # Exclude _id field from the result
            
            if result:
                print(result)
                print('Reading successful!')
                return result
            else:
                print("No matching document found.")
                return None
        except Exception as e:
            print(f'Reading failed. Error: {e}')
            return None

    def read_many(self, read_filter):
        """
        Reads and returns multiple documents matching the filter.

        Args:
            read_filter (dict): The filter to apply to the read operation.

        Returns:
            pymongo.cursor.Cursor: A cursor object for iterating over the results.
        """
        print('Attempting to Read (Many). . . ')
        try:
            # Attempt to find all documents matching the filter
            cursor = self.collection.find(read_filter, {"_id": False})  # Exclude _id field from the results
            print('Reading successful!')
            return cursor
        except Exception as e:
            print(f'Reading failed. Error: {e}')
            return None

    def update(self, update_filter, update_input):
        """
        Updates documents matching the filter with the provided data.

        Args:
            update_filter (dict): The filter to identify documents to update.
            update_input (dict): The update data using the $set operator.

        Returns:
            pymongo.results.UpdateResult: An object containing update statistics.
        """
        print('Attempting to Update. . . ')
        try:
            # Attempt to update documents matching the filter
            result = self.collection.update_many(update_filter, {"$set": update_input})
            print(f'Update successful! Modified {result.modified_count} document(s).')
            return result
        except Exception as e:
            print(f'Update failed. Error: {e}')
            return None

    def delete(self, delete_filter):
        """
        Deletes documents matching the filter.

        Args:
            delete_filter (dict): The filter to identify documents to delete.

        Returns:
            pymongo.results.DeleteResult: An object containing delete statistics.
        """
        print('Attempting to Delete. . . ')
        try:
            # Attempt to delete documents matching the filter
            result = self.collection.delete_many(delete_filter)
            print(f'Deletion successful! Deleted {result.deleted_count} document(s).')
            return result
        except Exception as e:
            print(f'Deletion failed. Error: {e}')
            return None

