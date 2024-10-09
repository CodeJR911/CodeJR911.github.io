from pymongo import MongoClient
from bson.objectid import ObjectId


    
class AnimalShelter (object):
    """ CRUD operations for Animal collection in MongoDB """
    
    def __init__(self, username, password):
        # Initializing the MongoClient. This helps to 
        # access the MongoDB databases and collections. 
        self.client = MongoClient('mongodb://%s:%s@localhost:39329/test?authSource=AAC'%("aacuser", "aacuser"))
        self.database = self.client['AAC']
        # Complete this create method to implement the C in CRUD
    
    def create(self, data):
        """
        Adds a new document to the collection.

        Args:
            data: A dictionary representing the document to be added.

        Returns:
            True if the insertion was successful, False otherwise.
        """
        #Checking to see if the data is none
        if data is not None:
            try:
                #Try to insert data into the database
                insert = self.database.animals.insert_one(data)  # data should be dictionary
                #Check if data was inserted
                return insert.inserted_id is not None
            except Exception as e:
                #Print out exception if there is one
                print(f"An error occurred while inserting data: {e}")
                return False
        else:
            #Raise exception if nothing to save
            raise Exception("Nothing to save, because data parameter is empty")
            
            
            # Complete this create method to implement the R in CRUD

    def read(self, criteria=None):
        """
        Retrieves documents from the collection based on the given criteria.

        Args:
            criteria: A dictionary specifying the search criteria. If None, all documents are returned.

        Returns:
            A cursor object for iterating over the matching documents.
        """
        #Check if criteria is not none
        if criteria is not None:
            try:
                #Try to read data from the database
                data = self.database.animals.find(criteria, {"_id": False})
                return data
            except Exception as e:
                #Print out exception if there is one
                print(f"An error occurred while reading data: {e}")
                return None
        else:
            try:
                #Try to read all data from the database
                data = self.database.animals.find({}, {"_id": False})
                return data
            except Exception as e:
                #Print out exception if there is one
                print(f"An error occurred while reading data: {e}")
                return None
    
    def update(self, criteria, update_data):
        """
        Updates documents matching the criteria with the provided data.

        Args:
            criteria: A dictionary specifying the documents to update.
            update_data: A dictionary containing the update operations.

        Returns:
            The result of the update operation.
        """
        #Check if criteria and update data is not none
        if criteria is not None and update_data is not None:
            try:
                #Try to update data in the database
                update_result = self.database.animals.update_many(criteria, {"$set": update_data})
                return update_result.modified_count
            except Exception as e:
                #Print out exception if there is one
                print(f"An error occurred while updating data: {e}")
                return None
        else:
            #Raise exception if update was unsuccessful
            raise Exception("Update unsuccessful. Criteria and update data cannot be empty.")

    def delete(self, criteria):
        """
        Deletes documents matching the given criteria.

        Args:
            criteria: A dictionary specifying the documents to delete.

        Returns:
            The result of the delete operation.
        """
        #Check if criteria is not none
        if criteria is not None:
            try:
                #Try to delete data from the database
                delete_result = self.database.animals.delete_many(criteria)
                return delete_result.deleted_count
            except Exception as e:
                #Print out exception if there is one
                print(f"An error occurred while deleting data: {e}")
                return None
        else:
            #Raise exception if delete was unsuccessful
            raise Exception("Delete unsuccessful. Criteria cannot be empty.")

